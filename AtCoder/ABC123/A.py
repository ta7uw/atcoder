a_list = [int(input()) for _ in range(6)]

if max(a_list[:5]) - min(a_list[:5]) <= a_list[5]:
    print("Yay!")
else:
    print(":(")
