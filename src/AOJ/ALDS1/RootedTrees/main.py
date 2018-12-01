n = int(input())
node_list = []

for i in range(n):
    node_list.append(list(map(int, input().split())))

parents = [-1 for i in range(n)]
right = [None for i in range(n)]
left = [None for i in range(n)]
depth = [None for i in range(n)]


def get_children(num):
    c = left[num]
    r = []
    while c is not None:
        r.append(c)
        c = right[c]
    return r


def set_depth(num, p):
    depth[num] = p
    if right[num] is not None:
        set_depth(right[num], p)
    if left[num] is not None:
        set_depth(left[num], p + 1)


for i in range(n):
    node = node_list[i]
    v = node[0]
    d = node[1]
    for j in range(d):
        if j == 0:
            left[v] = node[2 + j]
        else:
            right[m] = node[2 + j]
        m = node[2 + j]
        parents[node[2 + j]] = v
for i in range(n):
    if parents[i] == -1:
        root = i
set_depth(root, 0)
for i in range(n):
    print("node " + str(i) + ":", end=" ")
    print("parent = " + str(parents[i]) + ",", end=" ")
    print("depth = " + str(depth[i]) + ",", end=" ")

    if parents[i] == -1:
        print("root,", end=" ")
    elif left[i] is None:
        print("leaf,", end=" ")
    else:
        print("internal node,", end=" ")
    print(get_children(i))
