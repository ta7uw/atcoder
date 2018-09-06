N = int(input())
K = int(input())
x_list = list(map(int, input().split()))

sum = 0

for x in x_list:
    A = 2 * x
    B = (K - x) * 2
    sum += B if A >= B else A

print(sum)
