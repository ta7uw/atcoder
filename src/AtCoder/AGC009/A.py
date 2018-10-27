N = int(input())
a_list = []
b_list = []

for i in range(N):
    a, b = map(int, input().split())
    a_list.append(a)
    b_list.append(b)

count = 0
for i in range(N-1, -1, -1):
    a = a_list[i]
    b = b_list[i]
    if a == 0:
        continue
    if b == 1:
        continue

    if count > 0:
        a += count
    if a % b == 0:
        continue

    margin = b - (a % b)
    count += margin
print(count)
