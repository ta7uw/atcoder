s = input()

like = 753
reuslt = []
for i in range(len(s)-2):
    num = s[i:i+3]
    num = int(num)
    ab = abs(like - num)
    reuslt.append(ab)
print(min(reuslt))