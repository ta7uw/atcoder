import bisect
N = int(input())
a_list = list(map(int, input().split()))
b_list = list(map(int, input().split()))
c_list = list(map(int, input().split()))

a_list.sort()
c_list.sort()
result = 0

for b in b_list:
    a_count = bisect.bisect_left(a_list, b)
    c_count = bisect.bisect_right(c_list, b)
    result += a_count*(len(c_list)-c_count)

print(result)

