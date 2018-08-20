N = int(input())
a_list = [a for a in map(int, input().split())]
a_list.insert(0, 0)
a_list.append(0)
S = 0
before = 0
for a in a_list:
    S += abs(a - before)
    before = a

for i in range(1, N+1):
    a = a_list[i]
    s = S + abs(a_list[i-1] - a_list[i+1]) - (abs(a_list[i-1] - a_list[i]) + abs(a_list[i] - a_list[i+1]))
    print(s)

