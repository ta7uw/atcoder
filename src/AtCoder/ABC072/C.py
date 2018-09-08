N = int(input())
a_list = list(map(int, input().split()))

input_map = {i: 0 for i in range(10**5+1)}
for a in a_list:
    input_map[a] += 1


max_num = 0
for i in range(1, 10**5):
    max_num = max(input_map[i-1] + input_map[i] + input_map[i+1], max_num)
print(max_num)
