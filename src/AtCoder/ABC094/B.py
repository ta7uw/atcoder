N, M, X = map(int, input().split())
a_list = list(map(int,input().split()))

to_0_count = 0
to_N_count = 0
for i in range(0, X):
    if i in a_list:
        to_0_count +=1
for i in range(X+1, N+1):
    if i in a_list:
        to_N_count +=1
print(min([to_0_count, to_N_count]))

