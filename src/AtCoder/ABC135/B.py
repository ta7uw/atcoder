N = int(input())
p_list = list(map(int, input().split()))

a_list = p_list.copy()
a_list.sort()

ans = 0

for i in range(N):
    p = p_list[i]
    a = a_list[i]
    if p != a:
        ans += 1

if ans == 2 or ans == 0:
    print("YES")
else:
    print("NO")
