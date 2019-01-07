class UnionFind:
    def __init__(self, n):
        self.parent = [i for i in range(n + 1)]
        self.rank = [0 for _ in range(n + 1)]

    def find(self, x):
        # If x is root
        if self.parent[x] == x:
            return x
        # If x is not root, search again by using x's parent
        else:
            self.parent[x] = self.find(self.parent[x])
            return self.parent[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
        # Make an edge from the root of lower tree to the root of higher tree
        if self.rank[x] < self.rank[y]:
            self.parent[x] = y
        else:
            self.parent[y] = x
            # If the height of tree the tree is the same, increase one of the heights by 1
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

    def check_same(self, x, y):
        return self.find(x) == self.find(y)