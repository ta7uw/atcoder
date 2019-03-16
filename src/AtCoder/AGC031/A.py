from collections import Counter

n = int(input())
s = input()
cnt = Counter(s)
ans = 1
MOD = 10 ** 9 + 7
for c, v in cnt.items():
    ans = ans * (v + 1) % MOD
print(ans - 1)
