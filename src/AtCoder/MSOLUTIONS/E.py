class FactMod:

    def __init__(self, n, mod):
        self.mod = mod
        self.f = [1] * (n + 1)
        for i in range(1, n + 1):
            self.f[i] = self.f[i - 1] * i % mod

        self.inv = [pow(self.f[-1], mod - 2, mod)]
        for i in reversed(range(1, n + 1)):
            self.inv.append(self.inv[-1] * i % mod)
        self.inv.reverse()

    def fact(self, n):
        """
        :return: n!
        """
        return self.f[n]

    def comb(self, n, r):
        """
        :return: nCr
        """
        return self.f[n] * self.inv[n - r] * self.inv[r] % self.mod


Q = int(input())
items = []
for i in range(Q):
    items.append(tuple(map(int, input().split())))

mod = 10 ** 6 + 3
fact_mod = FactMod(mod - 1, mod)

for x, d, n in items:
    if d == 0:
        print(pow(x, n, mod))
    elif x == 0:
        print(0)
    else:
        invd = pow(d, mod - 2, mod)

        xd = x * invd % mod
        limit = mod - xd
        if n > limit:
            print(0)
            continue

        r = xd + n - 1
        l = xd - 1
        tmp = pow(d, n, mod)
        print(fact_mod.fact(r) * fact_mod.inv[l] * tmp % mod)
