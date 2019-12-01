N, M = map(int, input().split())
from fractions import gcd

print(M - gcd(N, M))
