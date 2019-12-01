c1_list = list(map(int, input().split()))
c2_list = list(map(int, input().split()))
c3_list = list(map(int, input().split()))

for a1 in range(0, 101):
    for a2 in range(0, 101):
        for a3 in range(0, 101):
            b1 = c1_list[0] - a1
            b2 = c1_list[1] - a1
            b3 = c1_list[2] - a1
            if c2_list[0] == a2+b1 and c2_list[1] == a2+b2 \
                    and c2_list[2] == a2 + b3 and c3_list[0] == a3 + b1 \
                    and c3_list[1] == a3 + b2 and c3_list[2] == a3 + b3:
                print("Yes")
                exit()
print("No")
