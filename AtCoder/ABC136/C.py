N = int(input())
h_list = list(map(int, input().split()))

min_num = -1
ans = True
for i in range(N - 1):
    h = h_list[i]
    h2 = h_list[i + 1]
    if h >= h2:
        h_list[i] -= 1
        h -= 1
        if h2 < min_num or h > h2:
            ans = False
    else:
        h_list[i+1] -= 1
        h2 -= 1
    min_num = max(h, h2)
    #print(min_num, ans, h, h2)
# if min(h_list) == 0 and max(h_list) == 1:
#     print("Yes")
#     exit()

if ans:
    print("Yes")
else:
    print("No")
