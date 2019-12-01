S = input()

ans = 0
N = len(S)
for i in range(N):
    s = S[i]
    if s == "U":
        ans += N - (i + 1)
        if (i + 1) - 1 >= 1:
            ans += 2 * i
    else:
        ans += i
        ans += 2 * (N - (i + 1))

print(ans)
