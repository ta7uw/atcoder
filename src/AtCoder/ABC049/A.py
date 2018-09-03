c = input()
c = c.replace("a", "").replace("e", "").replace("i", "").replace("o", "").replace("u", "")
if len(c) == 0:
    print("vowel")
else:
    print("consonant")
