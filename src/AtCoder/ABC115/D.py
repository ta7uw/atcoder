n, x = map(int, input().split())

sum_p = [1]
sum_dim = [1]

for i in range(n):
    sum_p.append(sum_p[i] * 2 + 1)
    sum_dim.append(sum_dim[i] * 2 + 3)


def cal(n, rem):
    if n == 0:
        return 0 if rem<= 0 else 1
    elif rem <= 1 + sum_dim[n-1]:
        return cal(n - 1, rem - 1)
    else:
        return sum_p[n-1] + 1 + cal(n - 1, rem - 2 - sum_dim[n-1])


print(cal(n, x))