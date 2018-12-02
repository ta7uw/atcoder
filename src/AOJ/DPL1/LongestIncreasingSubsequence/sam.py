a = [1, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0]
import bisect
i = bisect.bisect_right(a, 2, 0, 2)
print(a)
a[i] = 2
print(a)