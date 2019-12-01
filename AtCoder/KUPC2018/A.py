N = int(input())
s_list = list(map(int, input().split()))
a_list = list(map(int, input().split()))

ans = 0
for i in range(N):
    a = a_list[i]
    s = s_list[i]
    if s * a > ans:
        ans = s * a
print(ans)
