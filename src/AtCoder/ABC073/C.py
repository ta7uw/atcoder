N = int(input())
a_list = {}
for i in range(N):
    a = int(input())
    if a in a_list:
        a_list[a] += 1
    else:
        a_list[a] = 1

count = 0
for a, i in a_list.items():
    if i % 2 == 0:
        continue
    else:
        count += 1
print(count)

