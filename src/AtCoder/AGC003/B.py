N = int(input())
a_list = [int(input()) for _ in range(N)]
split_a_list = []

pre = -1
for i, a in enumerate(a_list):
    if a == 0:
        split_a_list.append(sum(a_list[pre + 1:i]))
        pre = i
else:
    split_a_list.append(sum(a_list[pre + 1:N]))
ans = 0
for s in split_a_list:
    ans += s // 2
print(ans)
