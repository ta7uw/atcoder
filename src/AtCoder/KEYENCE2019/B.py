s = input()

for i in range(len(s)):
    for j in range(i, len(s)):
        if s[:i] + s[j:] == "keyence":
            print("YES")
            exit()
print("NO")