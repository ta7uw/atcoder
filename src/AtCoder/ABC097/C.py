s = input()
k = int(input())

length = len(s)
substring_list = []
for i in range(length):
    for j in range(1,k+1):
        substring_list.append(s[i:i+j])
result = list(set(substring_list))
result.sort()

print(result[k-1])
