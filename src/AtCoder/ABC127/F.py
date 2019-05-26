import heapq

Q = int(input())
b_sum = 0
a_list = []
left = []
right = []
res = 0

for i in range(Q):
    query = list(map(int, input().split()))
    if query[0] == 1:
        b_sum += query[2]

        if not left:
            a = query[1]
            heapq.heappush(left, -a)
        else:
            res += abs(query[1] + left[0])
            if query[1] <= -left[0]:
                heapq.heappush(left, -query[1])
            else:
                heapq.heappush(right, query[1])

        if len(left) < len(right):
            x = heapq.heappop(right)
            y = -left[0]
            res += y - x
            heapq.heappush(left, -x)
        elif len(left) > len(right) + 1:
            x = - heapq.heappop(left)
            if len(right) != 0:
                y = right[0]
            else:
                y = 0
            heapq.heappush(right, x)
    else:
        print(-left[0], res + b_sum)
