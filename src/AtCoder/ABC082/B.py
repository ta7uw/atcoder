s = input()
t = input()
s = [i for i in s]
t = [i for i in t]
s.sort()
t.sort()
t.reverse()
s = "".join(s)
t = "".join(t)
if s < t:
    print("Yes")
else:
    print("No")
