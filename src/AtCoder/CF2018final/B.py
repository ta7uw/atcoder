import math

N, M = map(int, input().split())
r_list = list(map(int, input().split()))

log_list = [math.log(i, 10) for i in range(1, N + 1)]
ans = N * math.log(M, 10)
ans -= sum(log_list)
for r in r_list:
    ans += sum(log_list[:r])
ans = math.ceil(ans)
print(ans)
