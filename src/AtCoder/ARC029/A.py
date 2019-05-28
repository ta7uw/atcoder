N = int(input())
t_list = [int(input()) for _ in range(N)]

if N == 1:
    print(t_list[0])
    exit()
ans = float("inf")
for bit in range(2 ** N):
    one = 0
    zero = 0
    for j in range(N):
        if 1 & bit >> j:
            one += t_list[j]
        else:
            zero += t_list[j]
    ans = min(ans, max(one, zero))

print(ans)
