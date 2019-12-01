S = input()
N = len(S)

right = []
left = []

for i, s in enumerate(S):
    if s == "R":
        right.append(i)
    else:
        left.append(i)

acc_r = [-1] * N
acc_l = [-1] *N

for i in range(len(left)-1, 0, -1):
    l = left[i]
    l2 = left[i-1]
    for j in range(l2, l+1):
        acc_r[j] = l

for i in range(N):
    if acc_r[i] == -1:
        acc_r[i] = left[0]

for i in range(len(right) - 1):
    r = right[i]
    r2 = right[i+1]
    for j in range(r, r2+1):
        acc_l[j] = r

for i in range(N):
    if acc_l[i] == -1:
        acc_l[i] = right[-1]


ans = [0] * N

for i, s in enumerate(S):
    if s == "R":
        tar = acc_r[i]
        if (tar - i) % 2 == 0:
            ans[tar] += 1
        else:
            ans[tar-1] += 1
    else:
        tar = acc_l[i]
        if (tar - i) % 2 == 0:
            ans[tar] += 1
        else:
            ans[tar + 1] += 1

for a in ans:
    print(a, end=" ")
