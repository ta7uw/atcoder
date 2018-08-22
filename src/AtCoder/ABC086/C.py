N = int(input())
plan = []
for i in range(N):
    p = list(map(int, input().split()))
    plan.append(p)
x = 0
y = 0
t = 0
for p in plan:
    margin = p[0]-t
    if (abs(p[1] - x) + abs(p[2] - y)) > margin:
        print("No")
        exit()
    if (abs(p[1] - x) + abs(p[2] - y)) % 2 != margin % 2:
        print("No")
        exit()
    t = p[0]
    x = p[1]
    y = p[2]

print("Yes")

