import heapq

N, K = map(int, input().split())
ab = []
for _ in range(N):
    ab.append(tuple(map(int, input().split())))

heapq.heapify(ab)

ans = 0
for i in range(K):
    a, b = heapq.heappop(ab)
    ans += a
    heapq.heappush(ab, (a + b, b))
print(ans)
