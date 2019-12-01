n = int(input())
a_list = list(map(int, input().split()))

min_list = []

for i in range(-100, 101):
    r = 0
    for a in a_list:
        num = abs(i-a)**2
        r += num
    min_list.append(r)
print(min(min_list))