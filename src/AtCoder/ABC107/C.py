N, K = map(int, input().split())
x_list = list(map(int, input().split()))

result = []
for i in range(N-(K-1)):
    start = i
    end = i + (K -1)
    result.append(abs(x_list[start]) + abs(x_list[end] - x_list[start]))
    result.append(abs(x_list[end]) + abs(x_list[end] - x_list[start]))
print(min(result))
