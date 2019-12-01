from itertools import permutations

tar = [4, 8, 15, 16, 23, 42]

print("? 1 2", flush=True)
first = int(input())
print("? 2 3", flush=True)
second = int(input())
print("? 4 5", flush=True)
third = int(input())
print("? 5 6", flush=True)
four = int(input())

a = []
for per in permutations(tar, 6):
    if per[0] * per[1] == first and per[1] * per[2] == second and \
            per[3] * per[4] == third and per[4] * per[5] == four:
        a = list(per)
        break

ans = []
for ab in a:
    ans.append(str(ab))
print("! " + " ".join(ans))
