N = int(input())
s_list = []
for i in range(N):
    s_list.append(input())

a = 0
both = 0
b = 0
ans = 0
for i, s in enumerate(s_list):
    ans += s.count("AB")
    if s[0] == "B" and s[-1] == "A":
        both += 1

    elif s[-1] == "A":
        a += 1

    elif s[0] == "B":
        b += 1

if a != 0:
    a -= 1
    ans += both
    if b != 0:
        b -= 1
        ans += 1
    ans += min(a, b)
else:
    if b != 0:
        b -= 1
        ans += both
    else:
        if both >= 2:
            ans += both - 1
print(ans)
