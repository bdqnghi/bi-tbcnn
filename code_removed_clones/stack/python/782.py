#
#    Licensed under the Apache License, Version 2.0 (the "License"); you may
#    not use this file except in compliance with the License. You may obtain
#    a copy of the License at
#
#         http://www.apache.org/licenses/LICENSE-2.0
#
#    Unless required by applicable law or agreed to in writing, software
#    distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
#    WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
#    License for the specific language governing permissions and limitations
#    under the License.

from heat.engine import api as engine_api
from heat.engine import notification


def send(stack): INDENT
    """Send usage notifications to the configured notification driver."""

    # The current notifications have a start/end:
    # see: https://wiki.openstack.org/wiki/SystemUsageData
    # so to be consistent we translate our status into a known start/end/error
    # suffix.
    level = notification.get_default_level()
    if stack.status == stack.IN_PROGRESS: INDENT
        suffix = 'start'
DEDENT     elif stack.status == stack.COMPLETE: INDENT
        suffix = 'end'
DEDENT     else: INDENT
        suffix = 'error'
        level = notification.ERROR

DEDENT     event_type = '%s.%s.%s' % ('stack',
                               stack.action.lower(),
                               suffix)

    notification.notify(stack.context, event_type, level,
                        engine_api.format_notification_body(stack))
DEDENT 
