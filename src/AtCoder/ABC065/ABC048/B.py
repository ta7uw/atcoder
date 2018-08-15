a, b, x = map(int, input().split())
def cal(n, x):
    if n== -1:
        return 0
    else:
        return n // x + 1
print(cal(b, x) - cal(a-1, x))
