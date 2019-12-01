n, m = map(int, input().split())
x_list = tuple(map(int, input().split()))
y_list = tuple(map(int, input().split()))

mod = 10 ** 9 + 7

x_sum = 0
for i in range(1, n + 1):
    x_sum += ((i - 1) * x_list[i - 1] - (n - i) * x_list[i - 1]) % mod
y_sum = 0
for i in range(1, m + 1):
    y_sum += ((i - 1) * y_list[i - 1] - (m - i) * y_list[i - 1]) % mod

print(x_sum * y_sum % mod )
