N = int(input())
p_list = list(map(int, input().split()))

count = 0
for i in range(N-1):
    if p_list[i] == i + 1:
        count += 1
        p_list[i+1] = p_list[i]
if p_list[N-1] == N:
    count += 1
print(count)

