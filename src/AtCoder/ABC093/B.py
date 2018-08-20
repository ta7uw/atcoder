A, B, K = map(int, input().split())
for i, num in enumerate(range(A, B + 1)):
    if i + 1 > K:
        break
    print(num)
x = []
for i, num in enumerate(range(B, A-1, -1)):
    if i + 1 > K:
        break
    x.append(num)
x.sort()
k = B - A +1
 
for i in x:
    if k < 2 * K:
        k += 1
    else:
        print(i)
