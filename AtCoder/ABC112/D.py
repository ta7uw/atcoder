import math
N, M  = list(map(int, input().split()))
 
s = M // N
r_list = []
for i in range(1, int(math.sqrt(M)) + 1):
    if M % i == 0 and i <= s:
        if M // i <= s:
            r_list.append(M // i)
        else:
            r_list.append(i)
r_list.sort()
r_list.reverse()
print(r_list[0])
