N = int(input())
max_num = 0
for i in range(N):
    max_num = i**2
    if max_num > N:
        print((i-1)**2)
        exit()
print(1)
