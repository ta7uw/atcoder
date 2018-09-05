N, M = map(int, input().split())
line = []

for i in range(M):
    ab = list(map(int, input().split()))
    line.append(ab)

start = 1
end = N
first = set()
second = set()

for l in line:
    if end in l:
        second.add(l[0])
        second.add(l[1])
    elif start in l:
        first.add(l[1])
        first.add(l[0])


for f in first:
    if f in second:
        print('POSSIBLE')
        exit()

print('IMPOSSIBLE')
