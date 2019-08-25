S = input()

prev = ""
ans = 0
tmp = ""
for s in S:
    tmp += s
    if tmp != prev:
        ans += 1
        prev = tmp
        tmp = ""

print(ans)
