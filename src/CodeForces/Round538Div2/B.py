N, M, K = map(int, input().split())
a_list = list(map(int, input().split()))

b_list = [i for i in range(N)]
b_list.sort(reverse=True, key=lambda x: a_list[x])
c_list = []
sum_beauties = 0

for i in range(K * M):
    sum_beauties += a_list[b_list[i]]
    c_list.append((a_list[b_list[i]], b_list[i]))

print(sum_beauties)
c_list.sort(key=lambda x: (x[1], x[0]))

for i in range(1, len(c_list)):
    if i % M == 0:
        print(c_list[i - 1][1] + 1, end=" ")
