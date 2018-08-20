S = input()
S = S.replace("a", "", 1).replace("b", "", 1).replace("c", "", 1)
print("Yes" if len(S) == 0 else "No")
