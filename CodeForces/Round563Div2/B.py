N = int(input())
a_list = list(map(int, input().split()))
even = False
odd = False
for a in a_list:
    if a % 2 != 0:
        odd = True
    else:
        even = True

if even and odd:
    a_list.sort()
    ans = a_list
else:
    ans = a_list
for a in ans:
    print(a, end=" ")
print()
