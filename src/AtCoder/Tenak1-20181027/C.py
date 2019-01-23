N = int(input())
a_list = [int(input()) for _ in range(N)]

a_list.sort(reverse=True)

half = N // 2

ans1 = 0
ans2 = 0
for i in range(half):
    if i == half - 1:
        ans1 += a_list[i]
        ans1 -= a_list[-(i + 1)]
    else:
        ans1 += 2 * a_list[i]
        ans1 -= 2 * a_list[-(i + 1)]
ans2 = ans1
if N % 2 != 0:
    ans1 += a_list[half - 1]
    ans1 -= a_list[- (half + 1)]
    ans2 += a_list[half]
    ans2 -= a_list[- half]

print(max(ans1, ans2))
