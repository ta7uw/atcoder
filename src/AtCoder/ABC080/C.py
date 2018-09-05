N = int(input())
f_list = []
p_list = []

for i in range(N):
    f = input()
    f_list.append(f)
for i in range(N):
    p = list(map(int, input().split()))
    p_list.append(p)

profit = []
for i in range(1, 2**10):
    sum = 0
    for f, p in zip(f_list, p_list):
        f = int(f.replace(" ", ""), 2)
        c = bin(f & i).count("1")
        sum += p[c]
    profit.append(sum)
print(max(profit))

