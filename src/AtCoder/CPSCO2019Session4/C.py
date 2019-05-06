from bisect import bisect_right, bisect_left

N, D = map(int, input().split())
r_list = list(map(int, input().split()))

r_list.sort()
ans = 0
for i in range(2, N):
    max_rate = r_list[i]
    idx = bisect_left(r_list, max_rate - D)
    ans += (i - idx) * (i - idx - 1) // 2
print(ans)
