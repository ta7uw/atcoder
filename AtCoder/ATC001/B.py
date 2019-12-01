class UnionFind:
    def __init__(self, n):
        self.parent = [i for i in range(n + 1)]
        self.rank = [i for i in range(n + 1)]

    def find(self, x):
        if self.parent[x] == x:
            return x

        else:
            self.parent[x] = self.find(self.parent[x])
            return self.parent[x]

    def unite(self, x, y):
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


N, Q = map(int, input().split())
answers = []
union_find = UnionFind(N)
for i in range(Q):
    p, a, b = map(int, input().split())
    if p == 0:
        union_find.unite(a, b)
    else:
        f = union_find.check_same(a, b)
        if f:
            answers.append("Yes")
        else:
            answers.append("No")

for ans in answers:
    print(ans)
