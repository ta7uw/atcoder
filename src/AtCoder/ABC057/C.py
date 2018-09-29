N = int(input())
import math
sq = math.sqrt(N)

count = 0
min_num = N
while count <= sq:
    count += 1
    if N % count == 0:
        A = count
        B = N / count
        num = len(str(int(max(A, B))))
        if min_num > num:
            min_num = num
print(num)
