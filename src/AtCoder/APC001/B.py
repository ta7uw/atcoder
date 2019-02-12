N = int(input())
a_list = list(map(int, input().split()))
b_list = list(map(int, input().split()))

a_cnt = 0
b_cnt = 0

for i in range(N):
    a = a_list[i]
    b = b_list[i]

    if a == b:
        continue
    elif a > b:
        a_cnt += a - b

    else:
        b_cnt += (b - a + 1) // 2
tmp = sum(b_list) - sum(a_list)
if a_cnt <= tmp and b_cnt <= tmp:
    print("Yes")
else:
    print("No")
