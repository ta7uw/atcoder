import sys

sys.setrecursionlimit(10 ** 9)


class UnionFind:
    def __init__(self, n):
        self.parent = [i for i in range(n + 1)]
        self.rank = [0 for _ in range(n + 1)]
        self.size = [1] * (n + 1)

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


H, W = map(int, input().split())
s_list = []
for i in range(H):
    s_list.append(input())
check = [[0 for _ in range(W)] for _ in range(H)]

brack_list = []
union_find = UnionFind(H * W)
for i in range(H):
    for j in range(W):
        if s_list[i][j] == "#":
            brack_list.append(i * W + j)
            if i - 1 >= 0 and s_list[i - 1][j] == ".":
                union_find.union(i * W + j, (i - 1) * W + j)
            if i + 1 < H and s_list[i + 1][j] == ".":
                union_find.union(i * W + j, (i + 1) * W + j)
            if j - 1 >= 0 and s_list[i][j - 1] == ".":
                union_find.union(i * W + j, i * W + j - 1)
            if j + 1 < W and s_list[i][j + 1] == ".":
                union_find.union(i * W + j, i * W + j + 1)

black = {}
white = {}
for i in range(H):
    for j in range(W):
        p = union_find.find(i * W + j)
        if s_list[i][j] == "#":
            if p in black:
                black[p] += 1
            else:
                black[p] = 1
        else:
            if p in white:
                white[p] += 1
            else:
                white[p] = 1

p = set(union_find.parent[:-1])
count = 0
for i in p:
    if i in black and i in white:
        count += white[i] * black[i]
print(count)
