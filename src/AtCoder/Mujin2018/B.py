A = int(input())
S =input()

no_man = False
if A == 0:
    no_man = True
for s in S:
    if s == "+":
        A += 1
    else:
        A -=1
        if A == 0:
            no_man = True
print("Yes" if  no_man else "No")
