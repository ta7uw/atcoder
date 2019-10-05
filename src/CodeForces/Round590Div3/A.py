"""
値段の合計を商品数で割って、切り上げを行なった値を出力。
切り上げを行うのは値段の合計以上にならないといけないから
"""

Q = int(input())
ans = []
for q in range(Q):
    N = int(input())
    a_list = list(map(int, input().split()))
    ans.append((sum(a_list) + N - 1) // N)

for a in ans:
    print(a)
