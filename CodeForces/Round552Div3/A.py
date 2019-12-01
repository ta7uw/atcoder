x1, x2, x3, x4 = map(int, input().split())

max_num = max(x1, x2, x3, x4)

item = [x1, x2, x3, x4]
item.remove(max_num)

ans = []
for a in item:
    ans.append(max_num - a)

for a in ans:
    print(a, end=" ")
print()
