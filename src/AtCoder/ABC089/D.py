h, w, d = map(int, input().split())
a_dict = dict()
for i in range(h):
    A = list(map(int, input().split()))
    for j in range(w):
        a_dict[A[j]] = [i+1, j+1]
q = int(input())
query = []
for i in range(q):
    query.append(list(map(int, input().split())))

a_list = [0 for _ in range(h*w+1)]
for i in range(1, h*w+1):
    if i + d <= h*w:
        pos = a_dict[i]
        d_pos = a_dict[i+d]
        a_list[i+d] += a_list[i] + abs(d_pos[0]-pos[0]) + abs(d_pos[1]-pos[1])
for i in range(q):
    l, r = query[i]
    print(a_list[r] - a_list[l])
