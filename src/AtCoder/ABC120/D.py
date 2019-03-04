class UnionFind:
    def __init__(self, n):
        self.parent = [i for i in range(n + 1)]
        self.rank = [0 for _ in range(n + 1)]
        self.size = [1] * (n + 1)
        self.group = [[i] for i in range(n + 1)]

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
        if x == y:
            return
        # Make an edge from the root of lower tree to the root of higher tree
        if self.rank[x] < self.rank[y]:
            self.parent[x] = y
            self.size[y] += self.size[x]
        else:
            self.parent[y] = x
            self.size[x] += self.size[y]
            # If the height of tree the tree is the same, increase one of the heights by 1
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

    def check_same(self, x, y):
        return self.find(x) == self.find(y)

    def get_size(self, x):
        return self.size[self.find(x)]

    def merge(self, x, y):
        """
        "データ構造をマージする一般的なテク"
        """
        x = self.find(x)
        y = self.find(y)
        if len(self.group[x]) < len(self.group[y]):
            x, y = y, x
        self.group[x].extend(self.group[y])
        self.group[y] = []
        self.parent[y] = x


def combination(n, r):
    """
    :param n: the count of different items
    :param r: the number of select
    :return: combination
    n! / (r! * (n - r)!)
    """
    r = min(n - r, r)
    result = 1
    for i in range(n, n - r, -1):
        result *= i
    for i in range(1, r + 1):
        result //= i
    return result


N, M = map(int, input().split())
items = []
for i in range(M):
    a, b = map(int, input().split())
    items.append((a, b))
items = list(reversed(items))

union_find = UnionFind(N)
ans = (N - 1) * N // 2
minus = 0

result = []
for i, ab in enumerate(items):
    a, b = ab
    ans -= minus
    result.append(ans)
    if union_find.check_same(a, b):
        minus = 0
    else:
        sa = union_find.get_size(a)
        sb = union_find.get_size(b)
        minus = sa * sb
    union_find.union(a, b)

for r in result[::-1]:
    print(r)
