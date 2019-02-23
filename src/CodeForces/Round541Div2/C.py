N = int(input())
a_list = list(map(int, input().split()))

a_list.sort()
import heapq

heapq.heapify(a_list)

cnt = 0
ans = []
while len(a_list) != 0:
    a = heapq.heappop(a_list)
    if cnt % 2 == 0:
        ans.append(a)
    else:
        ans.insert(0, a)
    cnt += 1

for a in ans:
    print(a, end=" ")
print()
