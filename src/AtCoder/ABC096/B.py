a= list(map(int, input().split()))
K = int(input())
a.sort()
print(a[2] * (2 ** K ) + a[1] + a[0])
