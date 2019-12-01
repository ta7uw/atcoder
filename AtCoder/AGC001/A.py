N = int(input())
l_list = list(map(int, input().split()))

l_list.sort()

result = 0

for i in range(0, 2*N, 2):
    l1 = l_list[i]
    result += l1
print(result)
