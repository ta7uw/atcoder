N = int(input())

odds = [i for i in range(1, N+1) if i % 2 != 0]

result = []
for odd in odds:
    z = []
    for i in range(1, odd+1):
        if odd % i == 0:
            z.append(i)

    if len(z) == 8:
        result.append(z)
print(len(result))
