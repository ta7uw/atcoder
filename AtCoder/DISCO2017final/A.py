import math

K = int(input())


def check(x, y, r):
    tmp = math.sqrt(x ** 2 + y ** 2)
    if tmp <= r:
        return True
    return False


ans1 = 0
for i in range(K, 101, K):
    for j in range(K, 101, K):
        if check(i, j, 100):
            ans1 += 1

ans2 = 0
if 150 % K == 0:
    for i in range(K, 151, K):
        for j in range(K, 151, K):
            if check(i, j, 150):
                ans2 += 1
    ans2 *= 4
else:
    ans2 += (1 + 4 * (300 // (K * 2) - 1))
    tmp = 0
    plus = K // 2
    for i in range(K + plus, 151, K):
        for j in range(K + plus, 151, K):
            if check(i, j, 150):
                tmp += 1
    ans2 += 4 * tmp

print(ans1 * 4, ans2)
