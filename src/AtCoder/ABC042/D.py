H, W, A, B = map(int, input().split())
mod = 10 ** 9 + 7
ans = 0
X = [i for i in range(H + W + 1)]
X[0] = 1
for i in range(2, H + W + 1):
    X[i] = X[i - 1] * i % mod
Y = X.copy()
Y[-1] = pow(Y[-1], mod - 2, mod)
for i in range(H + W, 1, -1):
    Y[i - 1] = i * Y[i] % mod


def combination(x, y):
    return X[x] * Y[y] * Y[x - y] % mod


for i in range(B, W):
    ans += (combination(H - A - 1 + i, i) * combination(A - 1 + W - i - 1, W - i -1))
    ans %= mod
print(ans)