from itertools import accumulate

N, W = map(int, input().split())
items = []
for i in range(N):
    items.append(tuple(map(int, input().split())))

w_max = items[0][0] + 3
w0 = items[0][0]
w0_list = []
w1_list = []
w2_list = []
w3_list = []
for item in items:
    w, v = item
    if w == w0:
        w0_list.append(v)
    if w == w0 + 1:
        w1_list.append(v)
    if w == w0 + 2:
        w2_list.append(v)
    if w == w0 + 3:
        w3_list.append(v)
w0_list = sorted(w0_list, reverse=True)
w1_list = sorted(w1_list, reverse=True)
w2_list = sorted(w2_list, reverse=True)
w3_list = sorted(w3_list, reverse=True)

w0_accum = tuple(accumulate(w0_list))
w1_accum = tuple(accumulate(w1_list))
w2_accum = tuple(accumulate(w2_list))
w3_accum = tuple(accumulate(w3_list))

ans = 0
for i in range(len(w0_list)+1):
    for j in range(len(w1_list)+1):
        for k in range(len(w2_list)+1):
            for m in range(len(w3_list)+1):
                if w0 * i + (w0 + 1) * j + (w0 + 2) * k + (w0 + 3) * m > W:
                    continue
                else:
                    tmp = 0
                    if i > 0:
                        tmp += w0_accum[i-1]
                    if j > 0:
                        tmp += w1_accum[j-1]
                    if k > 0:
                        tmp += w2_accum[k-1]
                    if m > 0:
                        tmp += w3_accum[m-1]
                    ans = max(ans, tmp)
print(ans)
