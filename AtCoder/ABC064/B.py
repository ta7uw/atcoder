N = int(input())
a_list = list(map(int, input().split()))

max_num = max(a_list)
min_num = min(a_list)
print(max_num-min_num)
