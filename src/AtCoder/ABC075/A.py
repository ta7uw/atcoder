ABC = list(map(int, input().split()))

r = {}
for i in ABC:
    if i in r:
        r[i] +=1
    else:
        r[i] = 1
for a, i in r.items():
    if i == 1:
        print(a)
        exit()

