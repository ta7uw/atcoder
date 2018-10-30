X = input()

x_length = len(X)
stack = []

for i in range(x_length):
    x = X[i]
    if x == "S":
        stack.append(x)

    elif x == "T" and stack and stack[-1] == "S":
        stack.pop()

    else:
        stack.append(x)
print(len(stack))
