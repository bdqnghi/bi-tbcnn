"""Manage Stack"""

import json
from time import sleep, time
from . import shutdown, http_util, api, config


def get_stack_id(name, no_error=False): INDENT
    """Get stack id"""

    end_point = '{}/environments?limit=-1'.format(api.V1)
    response = http_util.get(end_point)

    if response.status_code not in range(200, 300): INDENT
        shutdown.err(response.text)

DEDENT     data = json.loads(response.text)['data']
    for environment in data: INDENT
        if 'name' in environment and environment['name'] == name: INDENT
            return environment['id'].replace('e', 'st')

DEDENT DEDENT     if not no_error: INDENT
        shutdown.err('No such stack ' + name)
DEDENT     return None


DEDENT def remove(value_type, value): INDENT
    """Remove stack"""

    stack_id = None
    if value_type == 'name': INDENT
        stack_id = get_stack_id(value)
DEDENT     elif value_type == 'id': INDENT
        stack_id = value
DEDENT     else: INDENT
        shutdown.err('Type must me one of name or id')

DEDENT     end_point = '{}/environments/{}/?action=remove'.format(
        api.V1, stack_id)
    response = http_util.post(end_point, {})
    if response.status_code not in range(200, 300): INDENT
        shutdown.err('Could not remove stack: {}'.format(response.text))


DEDENT DEDENT def create(name, docker_compose_path, rancher_compose_path, stack_tags=None): INDENT
    """Create stack"""

    print 'Creating stack ' + name + '...'
    docker_compose = __get_docker_compose(docker_compose_path)
    rancher_compose = __get_rancher_compose(rancher_compose_path)

    payload = {
        "type": "stack",
        "startOnCreate": True,
        "name": name,
        "group": stack_tags,
        'dockerCompose': docker_compose,
        'rancherCompose': rancher_compose}
    end_point = '{}/projects/{}/stack'.format(
        api.V2_BETA, config.RANCHER_PROJECT_ID)
    response = http_util.post(end_point, payload)
    if response.status_code not in range(200, 300): INDENT
        if json.loads(response.text)['code'] == 'NotUnique': INDENT
            print 'Oops! Stack already exists. Let`s upgrade it...'
            upgrade(name, docker_compose_path, rancher_compose_path)
DEDENT         else: INDENT
            shutdown.err(response.text)
DEDENT DEDENT     stack_id = get_stack_id(name)
    __wait_for_active(stack_id)
    __wait_for_healthy(stack_id)
    print 'Stack ' + name + ' created'


DEDENT def __init_upgrade(name, docker_compose_path, rancher_compose_path): INDENT
    print 'Initializing stack ' + name + ' upgrade...'
    docker_compose = __get_docker_compose(docker_compose_path)
    rancher_compose = __get_rancher_compose(rancher_compose_path)

    payload = {'type': 'environment',
               'startOnCreate': True,
               'name': name,
               'dockerCompose': docker_compose,
               'rancherCompose': rancher_compose}
    end_point = '{}/environments/{}/?action=upgrade'.format(
        api.V1, get_stack_id(name))
    response = http_util.post(end_point, payload)
    if response.status_code not in range(200, 300): INDENT
        shutdown.err(response.text)
DEDENT     print 'Stack upgrade initialized'


DEDENT def __finish_upgrade(stack_id): INDENT
    end_point = '{}/environments/{}/?action=finishupgrade'.format(
        api.V1, stack_id)
    response = http_util.post(end_point, {})
    if response.status_code not in range(200, 300): INDENT
        shutdown.err(response.text)


DEDENT DEDENT def __wait_for_upgrade(stack_id): INDENT
    print 'Let\'s wait until stack upgraded...'

    timeout = config.STACK_UPGRADE_TIMEOUT
    stop_time = int(time()) + timeout
    state = None
    while int(time()) <= stop_time: INDENT
        state = __get_state(stack_id)
        if state == 'upgraded': INDENT
            print 'Stack ' + stack_id + ' upgraded'
            return
DEDENT         sleep(5)
DEDENT     shutdown.err(
        'Timeout while waiting to service upgrade. Current state is: ' + state)


DEDENT def __wait_for_active(stack_id): INDENT
    print 'Let`s wait until stack become active...'
    timeout = config.STACK_ACTIVE_TIMEOUT
    stop_time = int(time()) + timeout
    state = None
    while int(time()) <= stop_time: INDENT
        state = __get_state(stack_id)
        if state == 'active': INDENT
            print 'Stack ' + stack_id + ' active'
            return
DEDENT         sleep(5)
DEDENT     shutdown.err(
        'Timeout while waiting to service upgrade. Current state is: ' + state)


DEDENT def __wait_for_healthy(stack_id): INDENT
    print 'Let`s wait until stack become healthy...'
    timeout = config.STACK_HEALTHY_TIMEOUT
    stop_time = int(time()) + timeout
    health_state = None
    while int(time()) <= stop_time: INDENT
        health_state = __get_health_state(stack_id)
        if health_state == 'healthy': INDENT
            print 'Stack ' + stack_id + ' is now healthy'
            return
DEDENT         sleep(5)
DEDENT     shutdown.err(
        'Timeout while waiting to stack become healthy. Current health state is: ' +
        health_state)


DEDENT def __get(stack_id): INDENT
    end_point = '{}/environments/{}'.format(api.V1, stack_id)
    response = http_util.get(end_point)
    if response.status_code not in range(200, 300): INDENT
        shutdown.err(response.text)
DEDENT     return json.loads(response.text)


DEDENT def __get_state(stack_id): INDENT
    service = __get(stack_id)
    return service['state']


DEDENT def __get_health_state(stack_id): INDENT
    service = __get(stack_id)
    return service['healthState']

DEDENT def __get_docker_compose(docker_compose_path): INDENT
    try: INDENT
        with open(docker_compose_path) as file_object: INDENT
            return file_object.read()
DEDENT DEDENT     except IOError, ex: INDENT
        shutdown.err(
            'Could not open docker-compose file: {}\n{}'.format(
                docker_compose_path, ex.message))


DEDENT DEDENT def __get_rancher_compose(rancher_compose_path): INDENT
    if rancher_compose_path is None: INDENT
        return ''
DEDENT     else: INDENT
        try: INDENT
            with open(rancher_compose_path) as file_object: INDENT
                return file_object.read()
DEDENT DEDENT         except IOError, ex: INDENT
            shutdown.err(
                'Could not open rancher-compose file: {}\n{}'.format(
                    rancher_compose_path, ex.message))


DEDENT DEDENT DEDENT def upgrade(name, docker_compose_path, rancher_compose_path): INDENT
    """Upgrade stack"""

    stack_id = get_stack_id(name)
    __init_upgrade(name, docker_compose_path, rancher_compose_path)
    __wait_for_upgrade(stack_id)
    __finish_upgrade(stack_id)
    __wait_for_healthy(stack_id)
DEDENT 
