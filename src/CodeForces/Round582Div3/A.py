N = int(input())
x_list = list(map(int, input().split()))

ans = float("inf")

for i in range(N):
    tmp = 0
    one = 0
    x = x_list[i]
    for j in range(N):
        y = x_list[j]
        if abs(x - y) % 2 == 1:
            one += 1
    ans = min(ans, one)
print(ans)
