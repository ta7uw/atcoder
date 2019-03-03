S = input()

red = 0
blue = 0
ans = 0
for s in S:
    if s == "0":
        red += 1
        if blue >= 1:
            ans += 2
            red -= 1
            blue -= 1
    else:
        blue += 1
        if red >= 1:
            red -= 1
            blue -= 1
            ans += 2

print(ans)
