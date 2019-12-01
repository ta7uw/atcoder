N = int(input())
S = list(input())

acc = [0]
acc2 = [0]
for s in S:
    if s == ".":
        acc.append(acc[-1] + 1)
        acc2.append(acc2[-1])
    else:
        acc.append(acc[-1])
        acc2.append(acc2[-1] + 1)
acc.pop(0)

ans = float("inf")

for i in range(N):
    s = S[i]
    tmp = acc[-1] - acc[i]
    tmp2 = acc2[i]
    ans = min(ans, tmp + tmp2)
print(ans)
