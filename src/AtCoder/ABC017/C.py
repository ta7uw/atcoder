n, m = map(int, input().split())
l_list = []
r_list = []
s_list = []

for i in range(n):
    l, r, s = map(int, input().split())
    l_list.append(l)
    r_list.append(r)
    s_list.append(s)

point = 0

items = [0 for i in range(m+1)]
points = [0 for i in range(m+1)]
for i in range(n):
    l = l_list[i]
    r = r_list[i]
    s = s_list[i]
    items[l] += 1
    points[l] += s
    if r == m:
        continue
    items[r+1] -= 1
    points[r+1] -= s

for i in range(1, m):
    items[i+1] += items[i]
    points[i+1] += points[i]

min_num = float("inf")
if items.count(0) > 1:
    print(sum(s_list))


else:
    min_count = sorted(items)[1]
    for i in range(1, m+1):
        if items[i] == min_count:
            if min_num > points[i]:
                min_num = points[i]
    print(sum(s_list)-min_num)

