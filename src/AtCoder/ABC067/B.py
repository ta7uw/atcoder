N, K = map(int, input().split())
l_list = list(map(int, input().split()))
l_list.sort()
l_list.reverse()
r = 0
for i in range(K):
    r += l_list[i]
print(r)
