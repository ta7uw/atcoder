C, D = map(int, input().split())

ans = 0
start = 140
end = 170

for i in range(50):
    start = 140 * (2 ** i)
    end = 170 * (2 ** i)
    ans += max(0, min(D, end) - max(C, start))

print(ans)
