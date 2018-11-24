n = int(input())

a0 = 1
a1 = 1

aList = [a0, a1]

if n == 0:
    print(a0)
    exit()
elif n == 1:
    print(a1)
    exit()
else:
    for i in range(2, n+1):
        aList.append(aList[i-1] + aList[i-2])

    print(aList[n])
