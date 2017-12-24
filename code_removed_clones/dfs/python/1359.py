"""
Prince DFS module.
"""
__docformat__ = "restructuredtext en"

## Copyright (c) 2010 Emmanuel Goossaert 
##
## This file is part of Prince, an extra-light Python module to run
## MapReduce tasks in the Hadoop framework. MapReduce is a patented
## software framework introduced by Google, and Hadoop is a registered
## trademark of the Apache Software Foundation.
##
## Prince is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 3 of the License, or
## (at your option) any later version.
##
## Prince is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with Prince.  If not, see <http://www.gnu.org/licenses/>.

import prince
import config


def read(filenames, first=None, last=None): INDENT
    """
    Read the content of files on the DFS. Multiple file names can be
    specified, and it is possible to read only n lines at the beginning or
    at the end of the file. 'first' and 'last' being exclusive parameters,
    if both of them are used then only 'first' is used.

    :Parameters:
        filenames : string or list of strings
            Files to read from on the DFS.
        first : int
            Number of lines to read at the beginning of the file
        last : int
            Number of lines to read at the end of the file

    :Return:
        Lines of the file(s) on the DFS.

    :ReturnType:
        List of strings.
    """
    if not isinstance(filenames, list): filenames = [filenames]
    options = {'mapreduce': config.mapreduce_program,
               'filenames': ' '.join(filenames) }
    if first:   truncate = ' | head -n %s' % first
    elif last:  truncate = ' | tail -n %s' % last
    else:       truncate = ''
    commandline = '%(mapreduce)s dfs -cat %(filenames)s' + truncate
    return prince.run_program(commandline, options)


DEDENT def write(filename, content): INDENT
    """
    Write text to a file on the DFS

    :Parameters:
        filename : string
            File name where to write the text on the DFS
        content : string or list of two-item tuples
            If it is a string, the text is just written as it is.
            If it is a list of tuples, each tuple is written as a MapReduce
            entry (key, value), separated by the default separator.

    :Examples:
        dfs_write('foo', 'String of text')
        dfs_write('foo', (0, 0))
        dfs_write('foo', [(0, 1), (1, 1)])
    """
    if not isinstance(content, str): INDENT
        if not isinstance(content, list): INDENT
            content = [content]
DEDENT         content = '\n'.join(['%s%s%s' % (str(item[0]), '\t', str(item[1])) for item in content])
DEDENT     options = {'content':   content,
               'mapreduce': config.mapreduce_program,
               'filename':  filename }
    prince.run_program('echo "%(content)s" | %(mapreduce)s dfs -put - %(filename)s', options)



DEDENT def exists(path): INDENT
    """
    Test if a path exists on the DFS.
    NOTE: The current implementation is based on 'dfs -ls' and is therefore
          *very* slow. This is due to the fact that the implementation of
          'dfs -test -e' in the current Hadoop version (0.20.1) is buggy
          and cannot be used properly.

    :Parameters:
        path : string
            Path of which the existence on the DFS has to be tested.

    :Return: 
        True if the path exists, False otherwise

    :ReturnType:
        Boolean
    """
    options = {'mapreduce': config.mapreduce_program,
               'path':      path}
    found = prince.run_program('%(mapreduce)s dfs -ls %(path)s', options)
    return True if found else False

DEDENT 
