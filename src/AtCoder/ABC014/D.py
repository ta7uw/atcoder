class LCA:
    def __init__(self, n, graph):
        self.V = n
        self.graph = graph
        self.LOG_V = 20
        self.parents = [[-1 for _ in range(n)] for _ in range(self.LOG_V)]
        self.depth = [0 for _ in range(n)]
        self.D = [0 for _ in range(n)]
        self.root = 0

    def build(self):
        self.dfs(self.root, -1, 0, 0)
        parent = self.parents
        V = self.V
        for k in range(self.LOG_V - 1):
            for v in range(V):
                if parent[k][v] < 0:
                    parent[k + 1][v] = -1
                else:
                    parent[k + 1][v] = parent[k][parent[k][v]]

    def dfs(self, v, p, d, c):
        self.parents[0][v] = p
        self.depth[v] = d
        self.D[v] = c
        for to, cost in self.graph[v]:
            if to != p:
                self.dfs(to, v, d + 1, c + cost)

    def getAnc(self, v, n):
        parent = self.parents
        for k in range(self.LOG_V):
            if v != -1 and ((n >> k) & 1):
                v = parent[k][v]
        return v

    def execute_lca(self, u, v):
        depth = self.depth
        if depth[u] > depth[v]:
            u, v = v, u
        v = self.getAnc(v, depth[v] - depth[u])
        if u == v:
            return u
        parent = self.parents
        for k in range(self.LOG_V - 1, -1, -1):
            if parent[k][u] != parent[k][v]:
                u = parent[k][u]
                v = parent[k][v]
        return parent[0][u]


import sys

sys.setrecursionlimit(int(1e9))

n = int(input())

graph = [[] for _ in range(n)]
for i in range(n - 1):
    x, y = (int(i) for i in sys.stdin.readline().split())
    graph[x - 1].append([y - 1, 1])
    graph[y - 1].append([x - 1, 1])

q = int(input())
lca = LCA(n, graph)
lca.build()
depth = lca.depth
for i in range(q):
    a, b = (int(i) for i in sys.stdin.readline().split())
    num = depth[a - 1] + depth[b - 1] - 2 * depth[lca.execute_lca(a - 1, b - 1)] + 1
    print(num)