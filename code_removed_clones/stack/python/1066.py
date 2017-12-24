from datetime import datetime

from boto.resultset import ResultSet

class Stack: INDENT
    def __init__(self, connection=None): INDENT
        self.connection = connection
        self.creation_time = None
        self.description = None
        self.disable_rollback = None
        self.notification_arns = []
        self.outputs = []
        self.parameters = []
        self.stack_id = None
        self.stack_status = None
        self.stack_name = None
        self.stack_name_reason = None
        self.timeout_in_minutes = None

DEDENT     def startElement(self, name, attrs, connection): INDENT
        if name == "Parameters": INDENT
            self.parameters = ResultSet([('member', Parameter)])
            return self.parameters
DEDENT         elif name == "Outputs": INDENT
            self.outputs = ResultSet([('member', Output)])
            return self.outputs
DEDENT         else: INDENT
            return None

DEDENT DEDENT     def endElement(self, name, value, connection): INDENT
        if name == 'CreationTime': INDENT
            self.creation_time = datetime.strptime(value, '%Y-%m-%dT%H:%M:%SZ')
DEDENT         elif name == "Description": INDENT
            self.description = value
DEDENT         elif name == "DisableRollback": INDENT
            self.disable_rollback = bool(value)
DEDENT         elif name == "NotificationARNs": INDENT
            self.notification_arns = value
DEDENT         elif name == 'StackId': INDENT
            self.stack_id = value
DEDENT         elif name == 'StackName': INDENT
            self.stack_name = value
DEDENT         elif name == 'StackStatus': INDENT
            self.stack_status = value
DEDENT         elif name == "StackStatusReason": INDENT
            self.stack_status_reason = value
DEDENT         elif name == "TimeoutInMinutes": INDENT
            self.timeout_in_minutes = int(value)
DEDENT         elif name == "member": INDENT
            pass
DEDENT         else: INDENT
            setattr(self, name, value)

DEDENT DEDENT     def delete(self): INDENT
        return self.connection.delete_stack(stack_name_or_id=self.stack_id)

DEDENT     def describe_events(self, next_token=None): INDENT
        return self.connection.describe_stack_events(
            stack_name_or_id=self.stack_id,
            next_token=next_token
        )

DEDENT     def describe_resource(self, logical_resource_id): INDENT
        return self.connection.describe_stack_resource(
            stack_name_or_id=self.stack_id,
            logical_resource_id=logical_resource_id
        )

DEDENT     def describe_resources(self, logical_resource_id=None,
            physical_resource_id=None): INDENT
        return self.connection.describe_stack_resources(
            stack_name_or_id=self.stack_id,
            logical_resource_id=logical_resource_id,
            physical_resource_id=physical_resource_id
        )

DEDENT     def list_resources(self, next_token=None): INDENT
        return self.connection.list_stack_resources(
            stack_name_or_id=self.stack_id,
            next_token=next_token
        )

DEDENT     def update(self): INDENT
        rs = self.connection.describe_stacks(self.stack_id)
        if len(rs) == 1 and rs[0].stack_id == self.stack_id: INDENT
            self.__dict__.update(rs[0].__dict__)
DEDENT         else: INDENT
            raise ValueError("%s is not a valid Stack ID or Name" %
                self.stack_id)

DEDENT DEDENT     def get_template(self): INDENT
        return self.connection.get_template(stack_name_or_id=self.stack_id)

DEDENT DEDENT class StackSummary: INDENT
    def __init__(self, connection=None): INDENT
        self.connection = connection
        self.stack_id = None
        self.stack_status = None
        self.stack_name = None
        self.creation_time = None
        self.deletion_time = None
        self.template_description = None

DEDENT     def startElement(self, name, attrs, connection): INDENT
        return None

DEDENT     def endElement(self, name, value, connection): INDENT
        if name == 'StackId': INDENT
            self.stack_id = value
DEDENT         elif name == 'StackStatus': INDENT
            self.stack_status = value
DEDENT         elif name == 'StackName': INDENT
            self.stack_name = value
DEDENT         elif name == 'CreationTime': INDENT
            self.creation_time = datetime.strptime(value, '%Y-%m-%dT%H:%M:%SZ')
DEDENT         elif name == "DeletionTime": INDENT
            self.deletion_time = datetime.strptime(value, '%Y-%m-%dT%H:%M:%SZ')
DEDENT         elif name == 'TemplateDescription': INDENT
            self.template_description = value
DEDENT         elif name == "member": INDENT
            pass
DEDENT         else: INDENT
            setattr(self, name, value)

DEDENT DEDENT DEDENT class Parameter: INDENT
    def __init__(self, connection=None): INDENT
        self.connection = None
        self.key = None
        self.value = None

DEDENT     def startElement(self, name, attrs, connection): INDENT
        return None

DEDENT     def endElement(self, name, value, connection): INDENT
        if name == "ParameterKey": INDENT
            self.key = value
DEDENT         elif name == "ParameterValue": INDENT
            self.value = value
DEDENT         else: INDENT
            setattr(self, name, value)

DEDENT DEDENT     def __repr__(self): INDENT
        return "Parameter:\"%s\"=\"%s\"" % (self.key, self.value)

DEDENT DEDENT class Output: INDENT
    def __init__(self, connection=None): INDENT
        self.connection = connection
        self.description = None
        self.key = None
        self.value = None

DEDENT     def startElement(self, name, attrs, connection): INDENT
        return None

DEDENT     def endElement(self, name, value, connection): INDENT
        if name == "Description": INDENT
            self.description = value
DEDENT         elif name == "OutputKey": INDENT
            self.key = value
DEDENT         elif name == "OutputValue": INDENT
            self.value = value
DEDENT         else: INDENT
            setattr(self, name, value)

DEDENT DEDENT     def __repr__(self): INDENT
        return "Output:\"%s\"=\"%s\"" % (self.key, self.value)

DEDENT DEDENT class StackResource: INDENT
    def __init__(self, connection=None): INDENT
        self.connection = connection
        self.description = None
        self.logical_resource_id = None
        self.physical_resource_id = None
        self.resource_status = None
        self.resource_status_reason = None
        self.resource_type = None
        self.stack_id = None
        self.stack_name = None
        self.timestamp = None

DEDENT     def startElement(self, name, attrs, connection): INDENT
        return None

DEDENT     def endElement(self, name, value, connection): INDENT
        if name == "Description": INDENT
            self.description = value
DEDENT         elif name == "LogicalResourceId": INDENT
            self.logical_resource_id = value
DEDENT         elif name == "PhysicalResourceId": INDENT
            self.physical_resource_id = value
DEDENT         elif name == "ResourceStatus": INDENT
            self.resource_status = value
DEDENT         elif name == "ResourceStatusReason": INDENT
            self.resource_status_reason = value
DEDENT         elif name == "ResourceType": INDENT
            self.resource_type = value
DEDENT         elif name == "StackId": INDENT
            self.stack_id = value
DEDENT         elif name == "StackName": INDENT
            self.stack_name = value
DEDENT         elif name == "Timestamp": INDENT
            self.timestamp = datetime.strptime(value, '%Y-%m-%dT%H:%M:%SZ')
DEDENT         else: INDENT
            setattr(self, name, value)

DEDENT DEDENT     def __repr__(self): INDENT
        return "StackResource:%s (%s)" % (self.logical_resource_id,
                self.resource_type)

DEDENT DEDENT class StackResourceSummary: INDENT
    def __init__(self, connection=None): INDENT
        self.connection = connection
        self.last_updated_timestamp = None
        self.logical_resource_id = None
        self.physical_resource_id = None
        self.resource_status = None
        self.resource_status_reason = None
        self.resource_type = None

DEDENT     def startElement(self, name, attrs, connection): INDENT
        return None

DEDENT     def endElement(self, name, value, connection): INDENT
        if name == "LastUpdatedTimestamp": INDENT
            self.last_updated_timestampe = datetime.strptime(value,
                '%Y-%m-%dT%H:%M:%SZ')
DEDENT         elif name == "LogicalResourceId": INDENT
            self.logical_resource_id = value
DEDENT         elif name == "PhysicalResourceId": INDENT
            self.physical_resource_id = value
DEDENT         elif name == "ResourceStatus": INDENT
            self.resource_status = value
DEDENT         elif name == "ResourceStatusReason": INDENT
            self.resource_status_reason = value
DEDENT         elif name == "ResourceType": INDENT
            self.resource_type = value
DEDENT         else: INDENT
            setattr(self, name, value)

DEDENT DEDENT     def __repr__(self): INDENT
        return "StackResourceSummary:%s (%s)" % (self.logical_resource_id,
                self.resource_type)

DEDENT DEDENT class StackEvent: INDENT
    valid_states = ("CREATE_IN_PROGRESS", "CREATE_FAILED", "CREATE_COMPLETE",
            "DELETE_IN_PROGRESS", "DELETE_FAILED", "DELETE_COMPLETE")
    def __init__(self, connection=None): INDENT
        self.connection = connection
        self.event_id = None
        self.logical_resource_id = None
        self.physical_resource_id = None
        self.resource_properties = None
        self.resource_status = None
        self.resource_status_reason = None
        self.resource_type = None
        self.stack_id = None
        self.stack_name = None
        self.timestamp = None

DEDENT     def startElement(self, name, attrs, connection): INDENT
        return None

DEDENT     def endElement(self, name, value, connection): INDENT
        if name == "EventId": INDENT
            self.event_id = value
DEDENT         elif name == "LogicalResourceId": INDENT
            self.logical_resource_id = value
DEDENT         elif name == "PhysicalResourceId": INDENT
            self.physical_resource_id = value
DEDENT         elif name == "ResourceProperties": INDENT
            self.resource_properties = value
DEDENT         elif name == "ResourceStatus": INDENT
            self.resource_status = value
DEDENT         elif name == "ResourceStatusReason": INDENT
            self.resource_status_reason = value
DEDENT         elif name == "ResourceType": INDENT
            self.resource_type = value
DEDENT         elif name == "StackId": INDENT
            self.stack_id = value
DEDENT         elif name == "StackName": INDENT
            self.stack_name = value
DEDENT         elif name == "Timestamp": INDENT
            self.timestamp = datetime.strptime(value, '%Y-%m-%dT%H:%M:%SZ')
DEDENT         else: INDENT
            setattr(self, name, value)

DEDENT DEDENT     def __repr__(self): INDENT
        return "StackEvent %s %s %s" % (self.resource_type,
                self.logical_resource_id, self.resource_status)
DEDENT DEDENT 
