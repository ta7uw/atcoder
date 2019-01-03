n = int(input())
c_list = [int(input()) for _ in range(n)]
import bisect


def lis(n, c_list):
    L = [0 for i in range(n + 1)]
    L[0] = c_list[0]
    length = 1
    for i in range(1, n):
        if L[length - 1] < c_list[i]:
            L[length] = c_list[i]
            length += 1
        else:
            index = bisect.bisect_left(L, c_list[i], 0, length)
            L[index] = c_list[i]
    return length


print(n - lis(n, c_list))
