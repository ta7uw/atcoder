N, Q = map(int, input().split())

S = input()
items = []
for i in range(Q):
    items.append(input().split())

left_ok = -1
left_ng = N


def check_left(mid):
    flag = False
    tmp = mid
    for t, d in items:
        if t == S[tmp]:
            if d == "L":
                if tmp - 1 == -1:
                    flag = True
                    break
                tmp -= 1
            else:
                if tmp + 1 >= N:
                    break
                tmp += 1
    return flag


def check_right(mid):
    flag = False
    tmp = mid
    for t, d in items:
        if t == S[tmp]:
            if d == "R":
                if tmp + 1 == N:
                    flag = True
                    break
                tmp += 1
            else:
                if tmp - 1 == -1:
                    break
                tmp -= 1

    return flag


while abs(left_ng - left_ok) > 1:
    mid = (left_ok + left_ng) // 2
    if check_left(mid):
        left_ok = mid
    else:
        left_ng = mid

right_ok = N
right_ng = -1

while abs(right_ok - right_ng) > 1:
    mid = (right_ok + right_ng) // 2

    if check_right(mid):
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
