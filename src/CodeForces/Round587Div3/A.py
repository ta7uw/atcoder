N = int(input())
S = input()
a = 0
b = 0
ans = 0
T = ""
for i, s in enumerate(S):
    if s == "a":
        a += 1
    else:
        b += 1
    if i % 2 == 1:
        if a != b:
            if s == "a":
                s = "b"
                a -= 1
                b += 1
            else:
                s = "a"
                a += 1
                b -= 1
            ans += 1
    T += s
print(ans)
print(T)
