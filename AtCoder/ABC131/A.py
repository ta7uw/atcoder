S = input()

prev = ""
for s in S:
    if s == prev:
        print("Bad")
        exit()
    prev = s
print("Good")
