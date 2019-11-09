N = int(input())
ab = []
for i in range(N):
    a, b = map(int, input().split())
    ab.append((i, a, b))

sum_list = []
for i in range(N):
    _, a, b = ab[i]
    sum_list.append((a + b, i))
sum_list = sorted(sum_list, key=lambda x: -x[0])

ans = 0

for k in range(N):
    if k % 2 == 0:
        su = sum_list[k]
        ans += ab[su[1]][1]
    else:
        su = sum_list[k]
        ans -= ab[su[1]][2]
print(ans)
