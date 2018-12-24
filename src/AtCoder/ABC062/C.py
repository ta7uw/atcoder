H, W = map(int, input().split())

result = []
for h in range(1, H//2+1):
    Sa = W * h

    remain = H - h
    h2 = (remain + 1) // 2
    Sb1 = W * h2
    Sc1 = W * (remain - h2)
    result.append(max(Sa, Sb1, Sc1) - min(Sa, Sb1, Sc1))

    w = (W + 1) // 2
    Sb2 = w * remain
    Sc2 = (W - w) * remain
    result.append(max(Sa, Sb2, Sc2) - min(Sa, Sb2, Sc2))

for w in range(1, W//2+1):
    Sa = H * w

    remain = W - w
    w3 = (remain + 1) // 2
    Sb1 = H * w3
    Sc1 = H * (remain - w3)
    result.append(max(Sa, Sb1, Sc1) - min(Sa, Sb1, Sc1))

    h = (H + 1) // 2
    Sb2 = h * remain
    Sc2 = (H - h) * remain
    result.append(max(Sa, Sb2, Sc2) - min(Sa, Sb2, Sc2))

print(min(result))
