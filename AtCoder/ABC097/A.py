a,b,c,d = map(int, input().split())
ac = abs(c-a)
ab = abs(b-a)
bc = abs(c-b)

if ac <= d:
    print("Yes")
elif ab <= d and bc <= d:
    print("Yes")
else:
    print("No")
    

