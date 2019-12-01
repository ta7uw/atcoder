N = int(input())

L_list = [2, 1]
for i in range(2, N+1):
    L_list.append(L_list[i-1]+L_list[i-2])

print(L_list[N])
