N, M, X, Y = map(int, input().split())
x_list = list(map(int, input().split()))
y_list = list(map(int, input().split()))

x_list.sort()
y_list.sort()

for z in range(X+1, Y):
    if x_list[-1] < z <= y_list[0]:
        print("No War")
        exit()
print("War")
