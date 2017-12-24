__author__ = 'nik'


def dfs_loop(edges_list): INDENT
    loop_state = LoopState(0, {}, set())
    for n in reversed(edges_list.keys()): INDENT
        if n not in loop_state.explored: INDENT
            _dfs(edges_list, n, loop_state)
DEDENT DEDENT     return loop_state.finish_times


DEDENT def _dfs(edges_list, node, loop_state): INDENT
    loop_state.explored.add(node)
    for n in edges_list[node]: INDENT
        if n not in loop_state.explored: INDENT
            _dfs(edges_list, n, loop_state)
DEDENT DEDENT     loop_state.time += 1
    loop_state.finish_times[node] = loop_state.time


DEDENT class LoopState: INDENT
    def __init__(self, time, finish_times, explored): INDENT
        self.time = time
        self.finish_times = finish_times
        self.explored = explored
DEDENT DEDENT 
