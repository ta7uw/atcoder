s = int(input())


def f(num):
    if num % 2 == 0:
        return num // 2
    else:
        return 3 * num + 1


i = 1
pre = set()
pre.add(s)
while i < 10 ** 6 + 1:
    tmp = f(s)
    if tmp in pre:
        print(i + 1)
        exit()
    i += 1
    s = tmp
    pre.add(tmp)
