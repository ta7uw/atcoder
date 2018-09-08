S = input()
X = [i for i in "abcdefghijklmnopqrstuvwxyz"]

S = [s for s in S]
S.sort()

for x in X:
    if x not in S:
        print(x)
        exit()

print("None")
