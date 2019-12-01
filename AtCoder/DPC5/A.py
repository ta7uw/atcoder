n = int(input())
alIst = list(map(int, input().split()))
 
sumN = 0
 
for i in range(n):
    sumN += alIst[i]
 
mean = sumN / n
 
min_margin = float("inf")
frame = 0
 
for i in range(n):
    a = alIst[i]
    margin = abs(a-mean)
    if margin < min_margin:
        min_margin = margin
        frame = i
 
print(frame)