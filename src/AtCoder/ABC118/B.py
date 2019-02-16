N, M = map(int, input().split())
k_list = []
items = []
for i in range(N):
    tmp = tuple(map(int, input().split()))
    k_list.append(tmp[0])
    items.append(tmp[1:])

ans = set(items[0])

for i in range(1, N):
    item = items[i]
    item = set(item)
    ans = ans & item

print(len(ans))
