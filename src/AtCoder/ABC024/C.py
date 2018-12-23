n, d, k = map(int, input().split())
l_list = []
r_list = []
for i in range(d):
    l, r = map(int, input().split())
    l_list.append(l)
    r_list.append(r)

s_list = []
t_list = []
for i in range(k):
    s, t = map(int, input().split())
    s_list.append(s)
    t_list.append(t)

for i in range(k):
    s, t = s_list[i], t_list[i]
    now = s
    day = 0
    for j in range(d):
        l, r = l_list[j], r_list[j]

        if l <= now <= r:
            if t > now:
                if r >= t:
                    now = t
                else:
                    now = r
            if t < now:
                if l <= t:
                    now = t
                else:
                    now = l
        if now == t:
            print(j+1)
            break

