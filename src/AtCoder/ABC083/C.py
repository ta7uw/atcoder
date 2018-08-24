X, Y = map(int, input().split())

count = 0
ai = X
a  = 0
while a <= Y:
    a = ai * 2
    count +=1
    ai = a
print(count)
