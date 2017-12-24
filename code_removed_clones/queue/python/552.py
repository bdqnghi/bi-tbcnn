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

from heat.common import exception
from heat.engine import clients
from heat.engine import properties
from heat.engine import resource
from heat.openstack.common import log as logging


logger = logging.getLogger(__name__)


try: INDENT
    from marconiclient.queues.v1 import client as marconiclient
DEDENT except ImportError: INDENT
    marconiclient = None
    logger.info(_('marconiclient not available'))

    def resource_mapping(): INDENT
        return {}
DEDENT DEDENT else: INDENT
    def resource_mapping(): INDENT
        return {
            'OS::Marconi::Queue': MarconiQueue,
        }


DEDENT DEDENT class Clients(clients.OpenStackClients): INDENT
    '''
    Convenience class to create and cache client instances.
    '''
    def __init__(self, context): INDENT
        super(Clients, self).__init__(context)
        self._marconi = None

DEDENT     def marconi(self, service_type="queuing"): INDENT
        if self._marconi: INDENT
            return self._marconi

DEDENT         con = self.context
        if self.auth_token is None: INDENT
            logger.error(_("Marconi connection failed, no auth_token!"))
            return None

DEDENT         opts = {
            'os_auth_token': con.auth_token,
            'os_auth_url': con.auth_url,
            'os_project_id': con.tenant,
            'os_service_type': service_type,
        }
        auth_opts = {'backend': 'keystone',
                     'options': opts}
        conf = {'auth_opts': auth_opts}
        endpoint = self.url_for(service_type=service_type)

        self._marconi = marconiclient.Client(url=endpoint, conf=conf)

        return self._marconi


DEDENT DEDENT class MarconiQueue(resource.Resource): INDENT

    PROPERTIES = (
        NAME, METADATA,
    ) = (
        'name', 'metadata',
    )

    properties_schema = {
        NAME: properties.Schema(
            properties.Schema.STRING,
            _("Name of the queue instance to create."),
            required=True),
        METADATA: properties.Schema(
            properties.Schema.MAP,
            description=_("Arbitrary key/value metadata to store "
                          "contextual information about this queue."),
            update_allowed=True)
    }

    attributes_schema = {
        "queue_id": _("ID of the queue."),
        "href": _("The resource href of the queue.")
    }

    update_allowed_keys = ('Properties',)

    def __init__(self, name, json_snippet, stack): INDENT
        super(MarconiQueue, self).__init__(name, json_snippet, stack)
        self.clients = Clients(self.context)

DEDENT     def marconi(self): INDENT
        return self.clients.marconi()

DEDENT     def physical_resource_name(self): INDENT
        return self.properties[self.NAME]

DEDENT     def handle_create(self): INDENT
        '''
        Create a marconi message queue.
        '''
        queue_name = self.physical_resource_name()
        queue = self.marconi().queue(queue_name, auto_create=False)
        # Marconi client doesn't report an error if an queue with the same
        # id/name already exists, which can cause issue with stack update.
        if queue.exists(): INDENT
            raise exception.Error(_('Message queue %s already exists.')
                                  % queue_name)
DEDENT         queue.ensure_exists()
        self.resource_id_set(queue_name)
        return queue

DEDENT     def check_create_complete(self, queue): INDENT
        # set metadata of the newly created queue
        if queue.exists(): INDENT
            metadata = self.properties.get('metadata')
            if metadata: INDENT
                queue.metadata(new_meta=metadata)
DEDENT             return True

DEDENT         queue_name = self.physical_resource_name()
        raise exception.Error(_('Message queue %s creation failed.')
                              % queue_name)

DEDENT     def handle_update(self, json_snippet, tmpl_diff, prop_diff): INDENT
        '''
        Update queue metadata.
        '''
        if 'metadata' in prop_diff: INDENT
            queue = self.marconi().queue(self.resource_id, auto_create=False)
            metadata = prop_diff['metadata']
            queue.metadata(new_meta=metadata)

DEDENT DEDENT     def handle_delete(self): INDENT
        '''
        Delete a marconi message queue.
        '''
        if not self.resource_id: INDENT
            return

DEDENT         queue = self.marconi().queue(self.resource_id, auto_create=False)
        queue.delete()

DEDENT     def href(self): INDENT
        api_endpoint = self.marconi().api_url
        queue_name = self.physical_resource_name()
        if api_endpoint.endswith('/'): INDENT
            return '%squeues/%s' % (api_endpoint, queue_name)
DEDENT         else: INDENT
            return '%s/queues/%s' % (api_endpoint, queue_name)

DEDENT DEDENT     def _resolve_attribute(self, name): INDENT
        if name == 'queue_id': INDENT
            return self.resource_id
DEDENT         elif name == 'href': INDENT
            return self.href()
DEDENT DEDENT DEDENT 
