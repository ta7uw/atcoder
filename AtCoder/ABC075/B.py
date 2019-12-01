H, W = map(int, input().split())
s_list = []
for i in range(H):
    s_list.append("."+ input()+ ".")
s_list.append("."*(W+2))
s_list.insert(0,"."*(W+2))

result = []
for i in range(1, H+1):
    line = []
    for j in range(1, W+1):
        if s_list[i][j]=="#":
            line.append("#")
            continue
        count = 0
        count += 0 if s_list[i][j-1] == "." else 1
        count += 0 if s_list[i+1][j-1] == "." else 1
        count += 0 if s_list[i+1][j] == "." else 1
        count += 0 if s_list[i+1][j+1] == "." else 1
        count += 0 if s_list[i][j+1] == "." else 1
        count += 0 if s_list[i-1][j+1] == "." else 1
        count += 0 if s_list[i-1][j] == "." else 1
        count += 0 if s_list[i-1][j-1] == "." else 1
        line.append(str(count))
    result.append(line)
for i in range(H):
    print("".join(result[i]))


