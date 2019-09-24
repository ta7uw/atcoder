"""
配り方を全探索。二人に配るので1人に配る・配らないの2通りにカバンをわける方法と考えてもいい
"""
a_list = list(map(int, input().split()))

for i in range(1 << 4):
    f = 0
    s = 0
    for j in range(4):
        if i >> j & 1 == 1:
            f += a_list[j]
        else:
            s += a_list[j]
    if s == f:
        print("YES")
        exit()

print("NO")
