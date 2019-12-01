N, X = map(int, input().split())
input_list = []
for i in range(N):
    input_list.append(int(input()))
count = N
for i in input_list:
    X -= i
input_list.sort()
while True:
    X -= input_list[0]
    if X < 0:
        break
    count +=1
print(count)

