N = int(input())
A = int(input())
for a in range(A+1):
    for j in range(21):
        if a + 500 * j == N: 
            print("Yes")
            exit()
print("No")
