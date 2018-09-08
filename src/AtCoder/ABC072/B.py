s = input()

s = [h for i, h in enumerate(s, 1) if i % 2 != 0]
print("".join(s))
