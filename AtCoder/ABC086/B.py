a, b = input().split()
c = int(a + b)

for i in range(1000):
    if i * i == c:
        print("Yes")
        exit()
print("No")

