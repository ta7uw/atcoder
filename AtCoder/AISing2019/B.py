A, B = map(int, input().split())
p_list = tuple(map(int, input().split()))

first = []
second = []
third = []
for p in p_list:
    if p <= A:
        first.append(p)
    elif p <= B:
        second.append(p)
    else:
        third.append(p)

print(min(len(first), len(second), len(third)))
