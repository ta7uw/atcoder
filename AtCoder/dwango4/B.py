s = input()

prev_length = -1
cnt = 0
while len(s) >= 1:
    s = s.replace("25", "")
    cnt += 1
    if len(s) == prev_length:
        print(-1)
        exit()
    prev_length = len(s)
print(cnt)
