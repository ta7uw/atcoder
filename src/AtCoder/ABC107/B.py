H, W = map(int, input().split())
a_list = []
for i in range(H):
    a_list.append(input())
 
a2_list = []
for a in a_list:
    if a.count(".") == W:
        continue
    else:
        a2_list.append(a)
a3_list = []
for j in range(W):
    row = "".join([r[j] for r in a2_list])
    if row.count(".") == len(a2_list):
        continue
    else:
        a3_list.append(row)
 
for i in range(len(a3_list[0])):
    row = [r[i] for r in a3_list]
    print("".join(row))
