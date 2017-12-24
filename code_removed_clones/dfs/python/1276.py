import sys
try:  INDENT# pragma: no cover
    from astropy.io import fits
DEDENT except ImportError: INDENT
    import pyfits as fits

DEDENT import cpl

class ProcessingInfo(object): INDENT
    '''Support for reading input files and parameters from the FITS
    header of a CPL processed file.

    This is done through the FITS headers that were written by the DFS function
    called within the processing recipe.

    .. attribute:: name 

       Recipe name

    .. attribute:: version 

       Recipe version string

    .. attribute::  pipeline

       Pipeline name

    .. attribute:: cpl_version
    
       CPL version string

    .. attribute:: tag

       Tag name

    .. attribute:: calib

       Calibration frames from a FITS file processed with CPL.
       The result of this function may directly set as :attr:`cpl.Recipe.calib`
       attribute::
    
         import cpl
         myrecipe = cpl.Recipe('muse_bias')
         myrecipe.calib = cpl.dfs.ProcessingInfo('MASTER_BIAS_0.fits').calib

       .. note::

          This will not work properly for files that had
          :class:`astropy.io.fits.HDUList` inputs since they have assigned a
          temporary file name only.

    .. attribute:: raw

       Raw (input) frames

       .. note::

          This will not work properly for files that had
          :class:`astropy.io.fits.HDUList` inputs since they have assigned a
          temporary file name only.

    .. attribute:: param

       Processing parameters.
       The result of this function may directly set as :attr:`cpl.Recipe.param`
       attribute::
    
         import cpl
         myrecipe = cpl.Recipe('muse_bias')
         myrecipe.param = cpl.dfs.ProcessingInfo('MASTER_BIAS_0.fits').param

    .. attribute:: md5sum

       MD5 sum of the data portions of the output file (header keyword 
       'DATAMD5').

    .. attribute:: md5sums

       MD5 sums of the input and calibration files. :class:`dict` with the
       file name as key and the corresponding MD5 sum as value.

       .. note::

          Due to a design decision in CPL, the raw input files are not
          accompanied with the MD5 sum.
    '''

    def __init__(self, source, recno = -1): INDENT
        '''
        :param source: Object pointing to the result file header
        :type source: :class:`str` or :class:`astropy.io.fits.HDUList`
                      or :class:`astropy.io.fits.PrimaryHDU` or 
                      :class:`astropy.io.fits.Header`
        :param recno: Record number. Optional. If not given, the last record
                      (with the highest record number) is used.
        :type recno: :class:`int`
        '''
        if isinstance(source, str): INDENT
            header = fits.open(source)[0].header
DEDENT         elif isinstance(source, (fits.HDUList, list)): INDENT
            header = source[0].header
DEDENT         elif isinstance(source, fits.PrimaryHDU): INDENT
            header = source.header
DEDENT         elif isinstance(source, (fits.Header, dict)): INDENT
            header = source
DEDENT         else: INDENT
            raise ValueError('Cannot assign type {0} to header'.format(
                    source.__class__.__name__))
        
DEDENT         if recno < 0: INDENT
            for reccnt in range(1, 2**16): INDENT
                if 'HIERARCH ESO PRO REC{0} ID'.format(reccnt) not in header: INDENT
                    break
DEDENT DEDENT             recno += reccnt
DEDENT         self.name = header['HIERARCH ESO PRO REC{0} ID'.format(recno)]
        self.product = header['HIERARCH ESO PRO CATG']
        self.orig_filename = header['PIPEFILE']
        pipe_id = header.get('HIERARCH ESO PRO REC{0} PIPE ID'.format(recno))
        if pipe_id: INDENT
            self.pipeline, version = pipe_id.split('/')
            num_version = 0
            for i in version.split('.'): INDENT
                num_version = num_version * 100 + int(i)
DEDENT             self.version = (num_version, version)
DEDENT         else: INDENT
            self.pipeline =  None
            self.version = None
DEDENT         self.cpl_version = header.get('HIERARCH ESO PRO REC{0} DRS ID'.format(recno))
        self.md5sum = header.get('DATAMD5')
        self.md5sums = {}
        self.calib = ProcessingInfo._get_rec_keys(header, recno, 'CAL', 'CATG', 'NAME')
        for cat, md5 in ProcessingInfo._get_rec_keys(header, recno, 'CAL', 'CATG',
                                                     'DATAMD5').items(): INDENT
            if isinstance(md5, list): INDENT
                for i, m in enumerate(md5): INDENT
                    if m is not None: INDENT
                        self.md5sums[self.calib[cat][i]] = m
DEDENT DEDENT DEDENT             elif md5 is not None: INDENT
                self.md5sums[self.calib[cat]] = md5
DEDENT DEDENT         raw = ProcessingInfo._get_rec_keys(header, recno, 'RAW', 'CATG', 'NAME')
        if raw: INDENT
            self.tag = list(raw.keys())[0]
            self.raw = raw[self.tag]
            md5 = ProcessingInfo._get_rec_keys(header, recno, 'RAW', 'CATG',
                                               'DATAMD5')[self.tag]
            if isinstance(md5, list): INDENT
                for i, m in enumerate(md5): INDENT
                    if m is not None:  INDENT
                        self.md5sums[self.raw[i]] = m
DEDENT DEDENT DEDENT             elif md5 is not None: INDENT
                self.md5sums[self.raw] = md5
DEDENT DEDENT         else: INDENT
            self.tag = None
            self.raw = None
            self.input = None
DEDENT         param = ProcessingInfo._get_rec_keys(header, recno, 'PARAM', 'NAME', 'VALUE')
        self.param = dict()
        for k,v in param.items(): INDENT
            self.param[k] = ProcessingInfo._best_type(v)
            
DEDENT DEDENT     def create_recipe(self): INDENT
        '''Create a recipe and configure it with the parameters, calibration frames,
        and the input tag. The recipe version will be the latest available one.
        '''
        recipe = cpl.Recipe(self.name)
        recipe.param = self.param
        recipe.calib = self.calib
        recipe.tag = self.tag
        return recipe

DEDENT     def create_script(self, scriptfile = sys.stdout): INDENT
        '''Create a sample script that creates the recipe, configures it with
        the parameters, calibration frames and input tags, and finally
        starts the recipe.
        '''
        if isinstance(scriptfile, str): INDENT
            scriptfile = file(scriptfile, mode='w')
DEDENT         scriptfile.write('import cpl\n\n')
        scriptfile.write('# Recipe: {0}.{1}, Version {2}, CPL version {3}\n'.format(
                self.pipeline, self.name, self.version[1], self.cpl_version))
        scriptfile.write('{0} = cpl.Recipe({1}, version = {2})\n'.format(
                self.name, repr(self.name), repr(self.version[0])))
        scriptfile.write('\n# Parameters:\n')
        for k,v in self.param.items(): INDENT
            scriptfile.write('{0}.param.{1} = {2}\n'.format(self.name, k, repr(v)))
DEDENT         if self.calib: INDENT
            scriptfile.write('\n# Calibration frames:\n')
DEDENT         for k,v in self.calib.items(): INDENT
            scriptfile.write('{0}.calib.{1} = {2}\n'.format(self.name, k, repr(v)))
DEDENT         scriptfile.write('\n# Process input frames:\n')
        scriptfile.write('{0}.tag = {1}\n'.format(self.name, repr(self.tag)))
        scriptfile.write('res = {0}({1})\n'.format(self.name, repr(self.raw)))
#        scriptfile.write('{0} = res.{1}\n'.format(self.product.lower(), self.product))
#        scriptfile.write('{0}.writeto({1})\n'.format(self.product.lower(),
#                                                     repr(self.orig_filename)))

DEDENT     def __str__(self): INDENT
        s = 'Recipe: {0}, Version {1}, CPL version {2}\n'.format(
            self.name, self.version, self.cpl_version)
        s += 'Parameters:\n'
        for k,v in self.param.items(): INDENT
            s += ' {0}.{1}.{2} = {3}\n'.format(self.pipeline, self.name, k, v)
DEDENT         if self.calib: INDENT
            s += 'Calibration frames:\n'
DEDENT         for k,v in self.calib.items(): INDENT
            if isinstance(v, (str, unicode)): INDENT
                s += ' {0} {1}\n'.format(v,k)
DEDENT             else: INDENT
                m = max(len(n) for n in v)
                for n in v: INDENT
                    s += ' {0:<{width}} {1}\n'.format(n, m, width = m)
DEDENT DEDENT DEDENT         if self.raw is not None: INDENT
            s += 'Input frames:\n'
            if isinstance(self.raw, (str, unicode)): INDENT
                s += ' {0} {1}\n'.format(self.raw, self.tag)
DEDENT             else: INDENT
                m = max(len(n) for n in self.raw)
                for n in self.raw: INDENT
                    s += ' {0:<{width}} {1}\n'.format(n, self.tag, width = m)
DEDENT DEDENT DEDENT         return s

DEDENT     def printinfo(self): INDENT
        '''Print the recipe information to standard output.
        '''
        print(str(self))

DEDENT     @staticmethod
    def _get_rec_keys(header, recno, key, name, value): INDENT
        '''Get a dictionary of key/value pairs from the DFS section of the
        header.

        :param key: Common keyword for the value. Usually 'PARAM' for
                    parameters, 'RAW' for raw frames, and 'CAL' for
                    calibration frames.
        :type key: :class:`str`
        :param recno: Record number.
        :type recno: :class:`int`
        :param name: Header keyword (last part) for the name of each key
        :type name: :class:`str`
        :param value: Header keyword (last part) for the value of each key
        :type name: :class:`str`

        When the header

          HIERARCH ESO PRO REC1 PARAM1 NAME = 'nifu'
          HIERARCH ESO PRO REC1 PARAM1 VALUE = '1'
          HIERARCH ESO PRO REC1 PARAM2 NAME = 'combine'
          HIERARCH ESO PRO REC1 PARAM2 VALUE = 'median'

        is called with

          ProcessingInfo._get_rec_keys(1, 'PARAM', 'NAME', 'VALUE')

        the returned dictionary will contain the keys

          res['nifu'] = '1'
          res['combine'] = 'median'
        '''
        res = dict()
        for i in range(1, 2**16): INDENT
            try: INDENT
                prefix = 'HIERARCH ESO PRO REC{0} {1}{2}'.format(recno, key, i)
                k = header['{0} {1}'.format(prefix, name)]
                fn = header.get('{0} {1}'.format(prefix, value))
                if k not in  res: INDENT
                    res[k] = fn
DEDENT                 elif isinstance(res[k], list): INDENT
                    res[k].append(fn)
DEDENT                 else: INDENT
                    res[k] = [ res[k], fn ]
DEDENT DEDENT             except KeyError: INDENT
                break
DEDENT DEDENT         return res

DEDENT     @staticmethod
    def _best_type(value): INDENT
        '''Convert the value to the best applicable type: :class:`int`,
        :class:`float`, :class:`bool` or :class`str`.

        :param value: Value to convert.
        :type value: :class:`str`
        '''
        for t in int, float: INDENT
            try: INDENT
                return t(value)
DEDENT             except ValueError: INDENT
                pass
DEDENT DEDENT         return {'true':True, 'false':False}.get(value, value)

DEDENT     @staticmethod
    def list(source): INDENT
        '''Get a list of all `ProcessingInfo` objects in the FITS header. The
        list is sorted by the execution order.

        :param source: Object pointing to the result file header
        :type source: :class:`str` or :class:`astropy.io.fits.HDUList`
                      or :class:`astropy.io.fits.PrimaryHDU` or
                      :class:`astropy.io.fits.Header`
        '''
        pi = []
        for i in range(1, 2**16): INDENT
            try: INDENT
                pi.append(ProcessingInfo(source, i))
DEDENT             except KeyError: INDENT
                break
DEDENT DEDENT         return pi

DEDENT DEDENT if __name__ == '__main__': INDENT
    for arg in sys.argv[1:]: INDENT
        print('{0}\nfile: {1}'.format('-' * 72, arg))
        pi = cpl.dfs.ProcessingInfo(arg)
        pi.printinfo()
DEDENT DEDENT 
