# ***** BEGIN LICENSE BLOCK *****
# Version: MPL 1.1/GPL 2.0/LGPL 2.1
#
# The contents of this file are subject to the Mozilla Public License Version
# 1.1 (the "License"); you may not use this file except in compliance with
# the License. You may obtain a copy of the License at
# http://www.mozilla.org/MPL/
#
# Software distributed under the License is distributed on an "AS IS" basis,
# WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
# for the specific language governing rights and limitations under the
# License.
#
# The Original Code is the Mozilla GoFaster Dashboard.
#
# The Initial Developer of the Original Code is
# Mozilla foundation
# Portions created by the Initial Developer are Copyright (C) 2011
# the Initial Developer. All Rights Reserved.
#
# Contributor(s):
#   William Lachance <wlachance@mozilla.com>
#
# Alternatively, the contents of this file may be used under the terms of
# either the GNU General Public License Version 2 or later (the "GPL"), or
# the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
# in which case the provisions of the GPL or the LGPL are applicable instead
# of those above. If you wish to allow use of your version of this file only
# under the terms of either the GPL or the LGPL, and not to allow others to
# use your version of this file under the terms of the MPL, indicate your
# decision by deleting the provisions above and replace them with the notice
# and other provisions required by the GPL or the LGPL. If you do not delete
# the provisions above, a recipient may use your version of this file under
# the terms of any one of the MPL, the GPL or the LGPL.
#
# ***** END LICENSE BLOCK *****

from lockfile import FileLock
import pickle
import os

QUEUE_FILE = os.path.dirname(os.path.realpath(__file__)) + '/../data/buildfaster-queue.pkl'

# Internal utility methods

def _get_queue(): INDENT
    try: INDENT
        return pickle.load(open(QUEUE_FILE, 'r'))
DEDENT     except: INDENT
        print "No queue, creating."
        return []

DEDENT DEDENT def _save_queue(queue): INDENT
    pickle.dump(queue, open(QUEUE_FILE, 'wb'))


# Accessor methods

DEDENT def append_job(tree, revision, submitter, return_email): INDENT
    lock = FileLock(QUEUE_FILE)
    with lock: INDENT
        queue = _get_queue()
        queue.append({'tree': tree, 'revision': revision,
                      'submitter': submitter,
                      'return_email': return_email })
        _save_queue(queue)

DEDENT DEDENT def pop_job(): INDENT
    lock = FileLock(QUEUE_FILE)
    with lock: INDENT
        queue = _get_queue()
        next_job = None
        if len(queue) > 0: INDENT
            next_job = queue.pop()
            _save_queue(queue)
DEDENT         return next_job

DEDENT DEDENT def get_copy(): INDENT
    return _get_queue()

DEDENT def clear(): INDENT
    lock = FileLock(QUEUE_FILE)
    with lock: INDENT
        _save_queue([])
DEDENT DEDENT 
