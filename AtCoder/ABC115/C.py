n, k= map(int, input().split())
h_list = []

for i in range(n):
    h_list.append(int(input()))

h_list.sort()
result = float("inf")

for i in range(n-k+1):
    r = h_list[i+k-1] - h_list[i]
    if result >= r:
        result = r
print(result)