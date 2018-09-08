N, X = map(int, input().split())
x_list = list(map(int, input().split()))

x_list.sort()
def gcd(a, b):
    if a >= b:
        return a if b == 0 else gcd(b, a % b)
    else:
        return gcd(b, a)


D = abs(X-x_list[0])
for i in range(0, N):
    D = gcd(D,  abs(x_list[i]-X))

print(D)

