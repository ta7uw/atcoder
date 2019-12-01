H, W, N = map(int, input().split())
ab = []
for i in range(N):
    a, b = map(int, input().split())
    ab.append((a - 1, b - 1))

comb_map = {}

for a, b in ab:
    for k in range(3):
        for m in range(3):
            if 0 <= a - k < H - 2 and 0 <= b - m < W - 2:
                if (a - k, b - m) in comb_map.keys():
                    comb_map[(a - k, b - m)] += 1
                else:
                    comb_map[(a - k, b - m)] = 1

count = [0 for _ in range(10)]

for v in comb_map.values():
    count[v] += 1

count[0] = (H - 2) * (W - 2) - sum(count[1:])

for c in count:
    print(c)
