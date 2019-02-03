N, M = map(int, input().split())
x_list = list(map(int, input().split()))
x_list.sort()

margin = []
prev = x_list[0]
for i in range(1, M):
    margin.append(x_list[i] - prev)
    prev = x_list[i]

margin.sort(reverse=True)
print(x_list[-1] - x_list[0] - sum(margin[:N-1]))
