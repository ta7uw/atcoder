S = input()
S = S.split("+")

count = 0

for s in S:
    if s.count("0") == 0:
        count += 1

print(count)