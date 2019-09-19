S = input()
N = len(S)

acc = [S[0]]

for i in range(N):
    s = S[i]
    if s >= acc[-1]:
        acc.append(acc[-1])
    else:
        acc.append(s)
acc.pop(0)

ans = []

for i in range(N):
    if i == 0:
        ans.append("Mike")
    else:
        s = S[i]
        if acc[i - 1] < s:
            ans.append("Ann")
        else:
            ans.append("Mike")
for a in ans:
    print(a)
