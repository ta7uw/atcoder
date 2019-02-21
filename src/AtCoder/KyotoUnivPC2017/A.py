N, K = map(int, input().split())
a_list = list(map(int, input().split()))

a_list.sort(reverse=True)

cnt = 0
num = 0
for a in a_list:
    cnt += 1
    num += a
    if num >= K:
        print(cnt)
        exit()
print(-1)
