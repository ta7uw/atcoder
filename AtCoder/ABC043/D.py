s = input()

before = 0
before_2 = 1

for i in range(2, len(s)):
    if s[before] == s[before_2]:
        print(before + 1, before_2 + 1)
        exit()
    if s[before] == s[i] and s[before] != s[before_2]:
        print(before + 1, i + 1)
        exit()
    before = before_2
    before_2 = i
if s[-1] == s[-2]:
    print(len(s) - 1, len(s))

else:
    print(-1, -1)
