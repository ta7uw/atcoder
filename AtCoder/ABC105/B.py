N = int(input())
result = False
for a in range(25):
    for b in range(14):
        if 4 * a + 7 *b == N:
            result = True
print("Yes" if result else "No")
