n = int(input())

p_list = list(map(int, input().split()))

ans = 0

for i in range(n - 2):
    p1 = p_list[i]
    p2 = p_list[i + 1]
    p3 = p_list[i + 2]
    if min(p1, p2, p3) != p2 and max(p1, p2, p3) != p2:
        ans += 1

print(ans)
