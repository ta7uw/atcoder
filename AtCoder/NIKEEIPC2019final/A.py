from itertools import accumulate

N = int(input())
a_list = list(map(int, input().split()))

ans = []
a_acc = [0] + list(accumulate(a_list))
for i in range(1, N + 1):
    tmp = 0
    for j in range(N - i + 1):
        tmp = max(tmp, a_acc[j + i] - a_acc[j])
    ans.append(tmp)
for a in ans:
    print(a)
