N, A, B= map(int, input().split())
result = []
for i in range(1, N + 1):
    tmp = i
    digits_sum = 0
    while tmp > 0:
        digits_sum += tmp % 10
        tmp //= 10
    if A <= digits_sum <= B:
        result.append(i)
print(sum(result))
