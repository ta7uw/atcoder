K, A, B = map(int, input().split())
tmp = K - A + 1
ans1 = K + 1
if tmp % 2 == 0:
    print(max(ans1, A + tmp // 2 * (B - A)))
else:
    print(max(ans1, A + tmp // 2 * (B - A) + 1))
