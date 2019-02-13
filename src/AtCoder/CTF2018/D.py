S = input()

ans = 1

prev = S[0]
for i, s in enumerate(S):
    if s > prev:
        continue
    else:
        if i == 0:
            continue
        ans += 1
        prev = s
print(ans)
