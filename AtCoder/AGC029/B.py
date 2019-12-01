N = int(input())
A_list = list(map(int, input().split()))
two_list = [2 ** i for i in range(32)]

count = 0
items = {}
for a in A_list:
    if a in items.keys():
        items[a] += 1
    else:
        items[a] = 1
A_list.sort(reverse=True)
import bisect

for a in A_list:
    if items[a] >= 1:
        index = bisect.bisect_left(two_list, a)
        for t in two_list[index:]:
            m = t - a
            if m in items.keys():
                if m == a and items[a] >= 2:
                    count += 1
                    items[a] -= 2
                    break

                elif m != a and items[m] >= 1 and items[a] >= 1:
                    count += 1
                    items[a] -= 1
                    items[m] -= 1
                    break
print(count)
