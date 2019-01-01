h, w = map(int, input().split())
n = int(input())
a_list = list(map(int, input().split()))

result = [[0 for _ in range(w)] for _ in range(h)]
height = 0
width = 0
count = -1

for i in range(1, n + 1):
    a = a_list[i - 1]
    for j in range(a):
        result[height][width] = i
        count += 1
        if width >= 0:
            width += 1
        else:
            width -= 1
        if count % w == w-1:
            height += 1
            if width >= 0:
                width = -1
            else:
                width = 0


for r in result:
    print(*r)
