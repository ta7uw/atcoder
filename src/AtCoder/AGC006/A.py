N = int(input())
s = input()
t = input()

S = s + t
r = len(S)
for i in range(N):
    ti = t[:(N-i)]
    index = s.find(ti)
    if index > -1:
        print(len(s)+len(t) - (len(s)-index))
        exit()
print(r)
