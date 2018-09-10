N, M = map(int, input().split())
import math
mod = 10**9 + 7

if abs(N-M)>=2:
    print(0)
elif abs(N-M) == 1:
    print(math.factorial(N)*math.factorial(M) % mod)
else:
    print(2*math.factorial(N)*math.factorial(M) % mod)
