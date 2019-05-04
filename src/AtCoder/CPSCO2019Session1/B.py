S = input()

from collections import Counter

c = Counter(list(S))
al = list(c)

cnt = 0

for i in range(len(al)):
    if i == 0:
        cnt = c[al[i]]
    else:
        if c[al[i]] == cnt:
            continue
        else:
            print("No")
            exit()
print("Yes")
