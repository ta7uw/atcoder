N = int(input())
S = input()
from math import factorial

cnt = 0

ans = 1
mod = 10 ** 9 + 7
for i in range(2 * N):
    s = S[i]
    if s == "W":
        if cnt == 0:
            print(0)
            exit()
        else:
            if cnt % 2 == 0:
                ans *= cnt
                ans %= mod
                cnt -= 1
            else:
                cnt += 1
    else:
        if cnt % 2 == 0:
            cnt += 1
        else:
            ans *= cnt
            ans %= mod
            cnt -= 1
if cnt != 0:
    print(0)
    exit()
ans *= factorial(N)
ans %= mod
print(ans)
