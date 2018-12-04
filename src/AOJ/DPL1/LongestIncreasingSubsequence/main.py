import bisect

n = int(input())
a_list = [int(input()) for i in range(n)]


def lis(n, A):
    L = [0 for i in range(n + 1)]
    L[0] = A[0]
    length = 1
    for i in range(1, n):
        if L[length - 1] < A[i]:
            L[length] = A[i]
            length += 1
        else:
            index = bisect.bisect_left(L, A[i], 0, length - 1)
            L[index] = A[i]
    return length


print(lis(n, a_list))
