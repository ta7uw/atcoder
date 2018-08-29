iN = int(input())
a_list = list(map(int, input().split()))

multi4 = len([a for a in a_list if a % 4 == 0])
odd_num = len([a for a in a_list if a % 2 != 0])

even_num = len(a_list) - odd_num
not4 = even_num - multi4

if not4 >0 :
    if odd_num <= multi4:
        print("Yes")
    else:
        print("No")

else:
    if odd_num <= multi4 + 1:
        print("Yes")
    else:
        print("No")

