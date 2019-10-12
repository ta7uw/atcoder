N = int(input())

ans = 0

f = 2
s = 3

for i in range(N - 2):
    ans += (1 * f * s)
    f = s
    s += 1

print(ans)
