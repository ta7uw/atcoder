N = int(input())
h_list = list(map(int, input().split()))
x_list = list(reversed(h_list))
ans = [0] * N

prev = 0
for i in range(N):
    x = x_list[i]
    if i == 0:
        prev = x
        continue
    if x >= prev:
        ans[N - (i + 1)] += ans[N - i] + 1
    else:
        ans[N - (i + 1)] = 0
    prev = x

print(max(ans))
