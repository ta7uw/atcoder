S = input()

length = len(S) - 1
ans = 0

for i in range(2 ** length):
    bit = bin(i)[2:].zfill(length)
    T = ""
    for j in range(len(S)):
        if j == 0:
            T += S[j]
            continue
        else:
            b = bit[j - 1]
            if b == "1":
                T += "+"
            T += S[j]
    ans += eval(T)
print(ans)
