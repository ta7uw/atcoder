"""
B. Alice and the List of Presents
https://codeforces.com/contest/1236/problem/B

あるプレゼント x は全ての箱のうち少なくとも一つの箱にいれる必要があるので
各箱に入れる・入れないの 2^M 通りから 1 を引いたものが
x を M 個の箱に入れる全てのパターンである。
プレゼントは合計 N 種類あるので (2^(M) - 1) ^ N が答え
"""
N, M = map(int, input().split())
mod = 10 ** 9 + 7

ans = pow(2, M, mod) - 1
ans = pow(ans, N, mod)
print(ans % mod)
