S = input()
S = S.replace("eraser", "").replace("erase", "").replace("dreamer", "").replace("dream", "")
if len(S) == 0:
    print("YES")
else:
    print("NO")
