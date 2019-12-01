x = input().split()
a = int(x[0])
b = int(x[1])
c = [a-b, a+b, a*b]
print(max(c))
