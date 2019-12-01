N = input()

before = ""
count = 1
for s in N:
    if before == -1:
        before = s
    else:
        if before == s:
            count += 1
            if count >= 3:
                print("Yes")
                exit()
        else:
            before = s
            count = 1
print("No")
