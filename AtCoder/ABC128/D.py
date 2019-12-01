N, K = map(int, input().split())
v_list = list(map(int, input().split()))

ans = 0

for a in range(min(N, K) + 1):
    for b in range(min(N - a, K - a) + 1):
        c = K - a - b
        tmp = v_list[:a:] + v_list[N - b:]
        tmp.sort()
        trash = 0
        for i in range(min(c, len(tmp))):
            t = tmp[i]
            if t < 0:
                trash += t
            else:
                break
        ans = max(sum(tmp) - trash, ans)
print(ans)
