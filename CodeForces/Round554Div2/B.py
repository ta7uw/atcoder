X = int(input())

cnt = 0
ans = []
length = len(bin(X)[2:])
bi = bin(X)[2:]
for i in range(length):
    bit = bi[i]
    if bit == "1":
        continue
    else:
        ans.append(length - i)
        cnt += 1
        X = X ^ (2 ** (length - i) - 1)
        bi = bin(X)[2:]
        f = True
        for b in bi:
            if b == "0":
                f = False
        if f:
            break
        cnt += 1
        X += 1
        bi = bin(X)[2:]

print(cnt)
for a in ans:
    print(a, end=" ")
print()
