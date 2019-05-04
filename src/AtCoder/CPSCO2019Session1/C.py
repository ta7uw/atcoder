import bisect
import collections
import copy
import fractions
import heapq
import itertools
import math
import string
import sys

inf = float("inf")
mod = 10 ** 9 + 7
d4 = [(1, 0), (0, -1), (-1, 0), (0, 1)]
d8 = [(1, 0), (1, -1), (0, -1), (-1, -1), (-1, 0), (-1, 1), (0, 1), (1, 1)]


def main():
    N, K = map(int, input().split())
    a_list = list(map(int, input().split()))

    ans = inf
    for comb in itertools.combinations(a_list, K):
        yen = sum(comb)
        tmp = 0

        while yen > 0:
            tmp += yen % 5
            tmp += (yen % 10) // 5
            yen //= 10
        ans = min(ans, tmp)
    print(ans)


if __name__ == '__main__':
    main()
