# Смежность вершин
inc = {
    1: [2, 8],
    2: [1, 3, 8],
    3: [2, 4, 8],
    4: [3, 7, 9],
    5: [6, 7],
    6: [5],
    7: [4, 5, 8],
    8: [1, 2, 3, 7],
    9: [4],
}

visited = set()  # Посещена ли вершина?
Q = []  # Очередь
BFS = []


# Поиск в ширину - ПВШ (Breadth First Search - BFS)
def bfs(v):
    if v in visited:  # Если вершина уже посещена, выходим
        return
    visited.add(v)  # Посетили вершину v
    BFS.append(v)  # Запоминаем порядок обхода
    # print("v = %d" % v)
    for i in inc[v]:  # Все смежные с v вершины
        if not i in visited:
            Q.append(i)
    while Q:
        bfs(Q.pop(0))


start = 1
bfs(start)  # start - начальная вершина обхода
print(BFS)