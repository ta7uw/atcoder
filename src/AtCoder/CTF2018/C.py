N = int(input())
x_list = list(map(int, input().split()))

x_list.sort()

ans = 0
for i in range(N):
    x = x_list[i]
    ans += x * (i - (N -1 - i))
print(ans)
