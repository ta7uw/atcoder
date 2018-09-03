H, W = map(int, input().split())
c_list = []
for i in range(H):
    c = input().split()
    c_list.append(c)
    c_list.append(c)

for c in c_list:
    print(c[0])
