S = input()
before = ""
r = 0
for i in range(len(S)):
    if i == 0:
        before = S[i]
    else:
        if before == S[i]:
            continue
        else:
            before = S[i]
            r += 1
print(r)
