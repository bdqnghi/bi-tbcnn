frontier = [(1, 1)]

TREE = 3
BEAR = 1
RASP = 2
FREE = 0
PASSED = 4

dx = [0, 0, 1, -1]
dy = [-1, 1, 0, 0]

def next_move(matrix): INDENT
    global frontier
    px, py = frontier[-1]
    matrix[px][py] = PASSED
    #pop front
    frontier = frontier[:-1]

    for i in xrange(len(dx)): INDENT
        x, y = px, py
        x += dx[i]
        y += dy[i]
        if matrix[x][y] == FREE or matrix[x][y] == RASP: INDENT
            frontier.append((x, y))

DEDENT DEDENT     return px, py


DEDENT 
