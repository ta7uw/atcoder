N, Q = map(int, input().split())

S = input()
items = []
for i in range(Q):
    t, d = input().split()
    items.append((t, d))

left_ok = -1
left_ng = N

while left_ng - left_ok > 1:
    mid = (left_ok + left_ng) // 2
    flag = False
    start = S[mid]
    tmp = mid
    for t, d in items:
        if t == start:
            if d == "L":
                if tmp - 1 == -1:
                    flag = True
                    break
                start = S[tmp - 1]
                tmp -= 1
            else:
                if tmp + 1 >= N:
                    break
                start = S[tmp + 1]
                tmp += 1

    if flag:
        left_ok = mid
    else:
        left_ng = mid

right_ok = N
right_ng = -1

while right_ok - right_ng > 1:
    mid = (right_ok + right_ng) // 2
    flag = False
    start = S[mid]
    tmp = mid
    for t, d in items:
        if t == start:
            if d == "R":
                if tmp + 1 == N:
                    flag = True
                    break
                start = S[tmp + 1]
                tmp += 1
            else:
                if tmp - 1 == -1:
                    break
                start = S[tmp - 1]
                tmp -= 1

    if flag:
        right_ok = mid
    else:
        right_ng = mid
ans = N
if left_ok != -1:
    ans -= left_ok + 1

if right_ok != N:
    ans -= N - right_ok

if left_ok >= right_ok:
    ans = 0

print(ans)
