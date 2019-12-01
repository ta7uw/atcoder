N = int(input())
a_list = list(map(int, input().split()))

even_list = [i for i in a_list if i % 2 == 0]
odd_list = [j for j in a_list if j % 2 == 1]

even_count = len(even_list)
odd_count = len(odd_list)

if odd_count % 2 !=0:
    print("NO")
else:
    print("YES")

