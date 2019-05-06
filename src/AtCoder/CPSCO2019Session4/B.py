N, D = map(int, input().split())
s_list = []
for i in range(D):
    s_list.append(input())

from itertools import combinations

ans = 0
for com in combinations(s_list, 2):
    day1 = com[0]
    day2 = com[1]
    tmp = 0
    for i in range(N):
        if day1[i] == "o" or day2[i] == "o":
            tmp += 1

    ans = max(ans, tmp)
print(ans)
