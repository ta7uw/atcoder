N = int(input())
D, X = map(int, input().split())
a_list = []
for i in range(N):
    a = int(input())
    a_list.append(a)

count = 0
for i in range(N):
    a = a_list[i]
    count += len([i +1 for i in range(D) if i % a == 0])
print(count + X)
