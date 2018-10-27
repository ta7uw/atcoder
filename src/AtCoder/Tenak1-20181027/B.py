A, B, K = map(int, input().split())
 
for i in range(K):
    if i % 2 == 0:
        if A % 2 != 0:
            A -=1
        tmp = A // 2
        A -= tmp
        B += tmp
 
    else:
        if B % 2 != 0:
            B -=1
        tmp = B // 2
        B -= tmp
        A += tmp
print(A, B)
