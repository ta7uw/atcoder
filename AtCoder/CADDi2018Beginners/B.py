n, h, w = map(int, input().split())
a_list = []
b_list = []

for i in range(n):
    a, b = map(int, input().split())
    a_list.append(a)
    b_list.append(b)
count = 0
for i in range(n):
    a = a_list[i]
    b = b_list[i]

    if a >= h and b >= w:
        count += 1
print(count)
