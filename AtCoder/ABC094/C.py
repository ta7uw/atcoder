N = int(input())
x_list = [i for i in list(map(int, input().split()))]
tmp = x_list.copy()
x_list.sort()
big = x_list[len(x_list)//2]
small = x_list[len(x_list)//2-1]

for x in tmp:
    if x >= big:
        print(small)
    else:
        print(big)

