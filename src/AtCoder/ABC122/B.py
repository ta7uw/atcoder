S = input()

t = ["A", "T", "C", "G"]
ans = 0
now = ""
for s in S:
    if s in t:
        now += s
    else:
        now = ""
    ans = max(ans, len(now))
print(ans)
