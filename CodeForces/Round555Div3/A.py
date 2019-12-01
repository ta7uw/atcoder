N = int(input())


def f(x):
    x += 1

    x = str(x)

    while x[-1] == "0":
        x = x[:-1]
    return x


prev = set()
prev.add(N)
n = N
while int(f(n)) not in prev:
    tmp = int(f(n))
    prev.add(tmp)
    n = tmp
print(len(prev))
