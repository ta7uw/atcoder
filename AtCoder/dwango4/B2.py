S = input()

cnt = 0
ans = 0

for s in S:
    if s == "2":
        cnt += 1
        ans = max(ans, cnt)
    else:
        cnt -= 1
        if cnt < 0:
            print(-1)
            exit()
print(ans if cnt == 0 else -1)
