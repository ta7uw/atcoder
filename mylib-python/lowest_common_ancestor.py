class LCA:
    def __init__(self, n):
        self.V = n
        self.graph = [[] for _ in range(n)]
        self.LOG_V = 20
        self.parents = [[-1 for _ in range(n)] for _ in range(self.LOG_V)]
        self.depth = [0 for _ in range(n)]
        self.D = [0 for _ in range(n)]
        self.root = 0

    def add_edge(self, a, b, c):
        self.graph[a].append((b, c))
        self.graph[b].append((a, c))

    def build(self):
        self.invoke_dfs()
        parent = self.parents
        V = self.V
        for k in range(self.LOG_V - 1):
            for v in range(V):
                if parent[k][v] < 0:
                    parent[k + 1][v] = -1
                else:
                    parent[k + 1][v] = parent[k][parent[k][v]]

    def invoke_dfs(self):
        parent = self.parents
        depth = self.depth
        D = self.D
        G = self.graph

        def dfs(v, p, d, c):
            parent[0][v] = p
            depth[v] = d
            D[v] = c
            for to, cost in G[v]:
                if to != p:
                    dfs(to, v, d + 1, c + cost)

        dfs(self.root, -1, 0, 0)

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
