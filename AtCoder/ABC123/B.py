a_list = [int(input()) for _ in range(5)]

min_index = -1
min_num = 9
for i, a in enumerate(a_list):
    last = int(str(a)[-1])
    if last == 0:
        continue
    if last <= min_num:
        min_num = last
        min_index = i

if min_index == -1:
    print(sum(a_list))
    exit()

ans = 0
for i, a in enumerate(a_list):
    last = int(str(a)[-1])
    if i == min_index:
        ans += a
    elif last == 0:
        ans += a
    else:
        ans += a
        ans += 10 - last
print(ans)
