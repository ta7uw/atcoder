N, K = map(int, input().split())
umai = {}
mazui = []
for _ in range(N):
    t, d = map(int, input().split())
    if t not in umai:
        umai[t] = d
    else:
        tmp = umai[t]
        if tmp < d:
            umai[t] = d
            mazui.append((t, tmp))
        else:
            mazui.append((t, d))

umai = sorted(umai.items(), key=lambda x: -x[1])
mazui = sorted(mazui, key=lambda x: -x[1])

umai_len = len(umai)
mazui_len = len(mazui)

acc_umai = [0 for _ in range(umai_len)]
acc_umai[0] = umai[0][1]
for i in range(umai_len - 1):
    acc_umai[i + 1] = acc_umai[i] + umai[i + 1][1]

acc_mazui = [0 for _ in range(mazui_len)]
if mazui_len > 0:

    acc_mazui[0] = mazui[0][1]
    for i in range(mazui_len - 1):
        acc_mazui[i + 1] = acc_mazui[i] + mazui[i + 1][1]
acc_mazui.insert(0, 0)

ans = []
for i in range(1, K + 1):
    if umai_len < i or mazui_len < K - i:
        continue
    ans.append(acc_umai[i - 1] + acc_mazui[K - i] + i ** 2)
print(max(ans))
