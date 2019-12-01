N = int(input())
v_list = list(map(int, input().split()))
c_list = list(map(int, input().split()))

ans = 0

for i in range(N):
    v = v_list[i]
    c = c_list[i]

    if v > c:
        ans += v -c
print(ans)
