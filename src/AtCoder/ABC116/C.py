N = int(input())
h_list = list(map(int, input().split()))

ans = 0
h_min = min(h_list)

ans += h_min

pre = h_min
for i in range(N):
    h = h_list[i]
    if i == 0:
        ans += h - h_min
        pre = h
    else:
        if h >= pre:
            ans += h - pre
            pre = h
        else:
            pre = h
print(ans)
