N = int(input())
s_list = [input() for _ in range(N)]
M = int(input())
t_list = [input() for _ in range(M)]
tmp = s_list.copy()
tmp.append("fdsfsdfsfs")
s_set = list(set(tmp))
result = []
for s in s_set:
    r = 0
    for i in s_list:
        if i == s:
            r += 1
    for j in t_list:
        if j == s:
            r -= 1
    result.append(r)
print(max(result))
