N, K = map(int, input().split())
a_list = list(map(int, input().split()))
s_list = [input() for _ in range(N)]
if N == K:
    print()
    exit()
want = [s_list[a - 1] for a in a_list]
prefix = []
for c in zip(*want):  # Unpacking
    if len(set(c)) == 1:
        prefix.append(c[0])
    else:
        break
if not prefix:
    print(-1)
    exit()

not_watch = set([i for i in range(N)]) - set([a - 1 for a in a_list])
not_watch = [s_list[i] for i in not_watch]

M = -1
for w in not_watch:
    for i, c in enumerate(zip(prefix, w)):
        if len(set(c)) != 1:
            i -= 1
            break
        M = max(M, i)

if len(prefix) > M + 1:
    print("".join(prefix[:M + 2]))
else:
    print(-1)
