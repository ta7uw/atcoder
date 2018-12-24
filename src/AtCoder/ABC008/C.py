n = int(input())
c_list = [int(input()) for _ in range(n)]

prime_count = [0 for _ in range(n)]
result = 0
for i, c in enumerate(c_list):
    count = 0
    for j, c2 in enumerate(c_list):
        if i == j:
            continue
        if c % c2 == 0:
            count += 1
    prime_count[i] = count
for i in range(n):
    pc = prime_count[i]
    if pc & 1 == 0:
        result += (pc + 2) / (2*(pc + 1))
    else:
        result += 1 / 2
print(result)
