N = int(input())
S = input()
eight = []
no = []
for i, s in enumerate(S):
    if s == "8":
        eight.append(i)
    else:
        no.append(i)
remain = N - 11
remain //= 2
if len(eight) <= remain:
    print("NO")
else:
    # eight = list(reversed(eight))
    eight = eight[remain:]
    first = eight[0]
    # print(first)
    if first <= 2 * remain:
        print("YES")
    else:
        print("NO")
