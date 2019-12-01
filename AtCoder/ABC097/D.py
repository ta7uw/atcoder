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
        if self.rank[x] < self.rank[y]:
            self.parent[x] = y
        else:
            self.parent[y] = x
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

    def check_same(self, x, y):
        return self.find(x) == self.find(y)


N, M = map(int, input().split())
p_list = list(map(int, input().split()))
union_find = UnionFind(N)
for i in range(M):
    x, y = map(int, input().split())
    union_find.union(x, y)

result = 0
for i in range(N):
    if union_find.check_same(p_list[i], i + 1):
        result += 1
print(result)
