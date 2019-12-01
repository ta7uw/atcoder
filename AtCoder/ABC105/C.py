N = int(input())
s = []
while True:
    if N % 2 :
        s.append("1")
        N -= 1
    else:
        s.append("0")
    N /= -2
    if N == 0:
        break
s.reverse()
print("".join(s))
