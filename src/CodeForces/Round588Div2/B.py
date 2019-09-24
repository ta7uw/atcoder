"""
https://codeforces.com/contest/1230/problem/B

Kが残っているときに i 桁目が0以外であれば0に置き換える。
ただし、先頭は0にはできないことに注意する。
1桁のときは0にできるので別処理にする。
"""
N, K = map(int, input().split())
S = input()

if N == 1 and K >= 1:
    print(0)
    exit()

T = ""
for i, s in enumerate(S):
    if i == 0:
        if K >= 1 and s != "1":
            K -= 1
            T += "1"
        else:
            T += s
    else:
        if K >= 1 and s != "0":
            K -= 1
            T += "0"
        else:
            T += s
print(T)
