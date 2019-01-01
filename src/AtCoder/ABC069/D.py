h, w = map(int, input().split())
n = int(input())
a_list = list(map(int, input().split()))

result = []

for i in range(1, n + 1):
    a = a_list[i - 1]
    for j in range(a):
        result.append(i)

for i in range(h):
    if i & 1 == 0:
        print(*result[i * w:(i + 1) * w])
    else:
        print(*result[i * w:(i + 1) * w][::-1])
