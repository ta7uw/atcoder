s = input()
s_split = [s[i] for i in range(len(s))]
result = 0

for i in range(2**(len(s)-1)):
    b = bin(i)[2:]
    b = b.zfill(len(s)-1)
    tmp = s_split.copy()

    for j in range(len(b)-1, -1, -1):
        if b[j] == "1":
            tmp.insert(-j-1, "+")

    before = ""
    num = 0
    for x in range(len(tmp)):
        if tmp[x] == "+":
            num += int(before)
            before = ""
        else:
            before += tmp[x]
    if len(before) != 0:
        num += int(before)
    result += num
print(result)