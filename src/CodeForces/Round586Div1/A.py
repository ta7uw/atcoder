N = int(input())
S = input()

from collections import defaultdict

di = defaultdict(int)

for s in S:
    di[s] += 1

one = di["n"]

zero = (N - 3 * one) // 4

for i in range(one):
    print(1, end=" ")
for i in range(zero):
    print(0, end=" ")
print()
