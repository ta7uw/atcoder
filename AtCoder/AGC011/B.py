from itertools import accumulate

N = int(input())
a_list = list(map(int, input().split()))
a_list.sort()

check = [False for _ in range(N)]

acc = tuple(accumulate(a_list))

for i in range(N - 1):
    if acc[i] * 2 >= a_list[i + 1]:
        check[i] = True
check[N - 1] = True

ans = 0
for c in check:
    if c:
        ans += 1
    else:
        ans = 0
print(ans)
