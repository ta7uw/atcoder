N = int(input())
a_list = list(map(int, input().split()))

if a_list[0] != a_list[-1]:
    print(N - 1)
    exit()

else:
    first = a_list[0]
    ans1 = 0
    rev_a = reversed(a_list)
    for i, a in enumerate(rev_a):
        if first != a:
            ans1 = N - (i + 1)
            break
    second = 0
    index = -1
    for i, a in enumerate(a_list):
        if a != first:
            second = a
            index = i
            break
    ans2 = N - (index + 1)
    print(max(ans1, ans2))
