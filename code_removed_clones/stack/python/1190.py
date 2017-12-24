import gdb
import weenix

class Stack: INDENT

    def __init__(self, gdbframe=None): INDENT
        if (gdbframe == None): INDENT
            gdbframe = gdb.newest_frame()
DEDENT         self._frames = []
        while (None != gdbframe): INDENT
            self._frames.append(weenix.stack.Frame(gdbframe))
            gdbframe = gdbframe.older()

DEDENT DEDENT     def contains(self, fname): INDENT
        for frame in self._frames: INDENT
            if (frame._func == fname): INDENT
                return True
DEDENT DEDENT         return False

DEDENT     def __str__(self): INDENT
        res = ""
        for i, frame in enumerate(self._frames): INDENT
            res += "#{0:<2} {1}\n".format(i, str(frame))
DEDENT         return res

DEDENT DEDENT class Frame: INDENT

    def __init__(self, gdbframe): INDENT
        self._func = "???" if gdbframe.name() == None else gdbframe.name()
        self._pc = gdbframe.find_sal().pc
        self._symtab = gdbframe.find_sal()
        self._args = {}
        if (gdbframe.function() != None): INDENT
            gdbframe.select()
            argstr = gdb.execute("info args", to_string=True)
            for line in argstr.split("\n"): INDENT
                parts = line.split("=", 1)
                if (len(parts) == 2): INDENT
                    self._args[parts[0].strip()] = parts[1].strip()

DEDENT DEDENT DEDENT DEDENT     def args(self): INDENT
        return self._args

DEDENT     def __str__(self, line=0): INDENT
        if (self._symtab.symtab == None): INDENT
            res = "0x{1:>08x} ?? ()".format(line, self._pc)
DEDENT         else: INDENT
            hasargs = False
            res = "0x{1:>08x} {2} (".format(line, self._pc, self._func)
            for arg in self._args.iterkeys(): INDENT
                hasargs = True
                res += arg + "=" + self._args[arg] + ", "
DEDENT             if (hasargs): INDENT
                res = res[:-2]
DEDENT             res += ") in {0}:{1}".format(self._symtab.symtab.filename, self._symtab.line)
DEDENT         return res
DEDENT DEDENT 
