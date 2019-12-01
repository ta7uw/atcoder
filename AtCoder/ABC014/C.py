n = int(input())
a_list = []
b_list = []

for i in range(n):
    a, b = map(int, input().split())
    a_list.append(a)
    b_list.append(b)

buy_list = [0 for _ in range(1000001)]

for i in range(n):
    a = a_list[i]
    b = b_list[i]
    buy_list[a] += 1
    if b == 1000000:
        continue
    buy_list[b+1] -= 1
for i in range(1, len(buy_list)):
    buy_list[i] += buy_list[i-1]
print(max(buy_list))
