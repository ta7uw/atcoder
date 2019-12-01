A, B = map(int, input().split())


def f(num):
    if num % 4 == 0:
        return num
    if num % 4 == 1:
        return 1

    if num % 4 == 2:
        return num + 1
    return 0


print(f(B) ^ f(A - 1))
