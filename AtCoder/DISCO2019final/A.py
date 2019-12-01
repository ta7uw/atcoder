N = int(input())
S = input()

ice = []
tmp = 0
for s in S:
    if s == ">":
        tmp += 1
    else:
        if tmp >= 1:
            ice.append(tmp)
        tmp = 0
else:
    if tmp >= 1:
        ice.append(tmp)
snow = 0
if len(ice) != 0:
    snow = N - sum(ice) - 1
else:
    print(N - 0.5)
    exit()
ans = 0
max_ice = max(ice)
cnt = 0
for ic in ice:
    if ic == max_ice and cnt == 0:
        cnt += 1
        ic += 1
    for k in range(ic):
        ans += 1 / (k + 2)
print(ans + snow)
