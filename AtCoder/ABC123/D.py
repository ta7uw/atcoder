X, Y, Z, K = map(int, input().split())
a_list = list(map(int, input().split()))
b_list = list(map(int, input().split()))
c_list = list(map(int, input().split()))

ab_items = []
for a in a_list:
    for b in b_list:
        ab_items.append(a + b)

ab_items.sort(reverse=True)
ab_items = ab_items[:K + 1]

ans = []
for c in c_list:
    for ab in ab_items:
        ans.append(c + ab)

ans.sort(reverse=True)

for i in range(K):
    print(ans[i])
