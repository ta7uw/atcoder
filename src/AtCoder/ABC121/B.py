N, M, C = map(int, input().split())
b_list = list(map(int, input().split()))

items = []
for i in range(N):
    items.append(list(map(int, input().split())))

ans = 0

for item in items:
    tmp = 0
    for i in range(M):
        a = item[i]
        b = b_list[i]
        tmp += a * b
    if tmp + C > 0:
        ans +=1
print(ans)
