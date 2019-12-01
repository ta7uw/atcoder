N = int(input())
num = 1
 
for i in range(1, 9):
    if 2**i <= N:
        num = 2**i
print(num)
