import heapq

N = int(input())
a_list = list(map(int, input().split()))

heapq.heapify(a_list)

ans = 0
day = 1
while len(a_list) != 0:
    a = heapq.heappop(a_list)
    if a >= day:
        ans += 1
        day += 1
print(ans)
