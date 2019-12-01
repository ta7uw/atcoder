N = int(input())
a1_list = list(map(int, input().split()))
a2_list = list(map(int, input().split()))
 
sum_list = []
for i in range(N):
    sum_list.append(sum(a1_list[:i+1]) + sum(a2_list[i:]))
print(max(sum_list))
