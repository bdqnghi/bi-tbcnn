class Graph(object):
    def __init__(self, count):
        self.count = count
        self.edges = {}

        for i in range(1, count + 1):
            self.edges[i] = []


    def add_edge(self, u, v):
        self.edges[u].append(v)
        self.edges[v].append(u)

    def get_path_length(self, t):
        return self.dist[t]

    def bfs(self, s):
        q = []

        self.dist = {}
        for i in range(1, self.count + 1):
            self.dist[i] = -1

        self.dist[s] = 0
        q.append(s)

        while len(q) != 0:  
            v = q.pop(0)
            for i in self.edges[v]:
                if self.dist[i] == -1:
                    q.append(i)
                    self.dist[i] = self.dist[v] + 1


if __name__ == "__main__":
    n, m = map(int, input().split())
    g = Graph(n)

    for i in range(0, m):
        u, v = map(int, input().split())
        g.add_edge(u, v)

    s, t = map(int, input().split())
    g.bfs(s)
    print(g.get_path_length(t))
