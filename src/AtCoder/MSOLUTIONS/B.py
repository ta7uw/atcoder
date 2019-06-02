S = input()
cnt = 0

for s in S:
    if s == "x":
        continue

    else:
        cnt += 1

if 15 - len(S) + cnt >= 8:
    print("YES")
else:
    print("NO")
