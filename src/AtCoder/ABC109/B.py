N = int(input())
before = ""
all = set()
check = True
for i in range(N):
    s = input()
    if i == 0:
        before = s
        all.add(s)
    else:
        if before[-1] == s[0]:
            before = s
            all.add(s)
        else:
            check = False
if check:
    print("Yes" if len(all)==N else "No")
else:
    print("No")
