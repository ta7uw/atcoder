S = input()

n = len(S)

start_0 = ""
start_1 = ""

for i in range(n):
    if i % 2 == 0:
        start_0 += "0"
        start_1 += "1"
    else:
        start_0 += "1"
        start_1 += "0"

ans_0 = 0
ans_1 = 0

for i in range(n):
    t1 = start_0[i]
    t2 = start_1[i]
    s = S[i]
    if t1 != s:
        ans_0 += 1
    if t2 != s:
        ans_1 += 1

print(min(ans_1, ans_0))
