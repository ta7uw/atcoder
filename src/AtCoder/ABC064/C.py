N = int(input())
a_list = list(map(int, input().split()))

color_set = set()
all = 0

for a in a_list:
    if 1 <= a <= 399:
        color_set.add("gray")
    elif 400 <= a <= 799:
        color_set.add("brown")
    elif 800 <= a <= 1199:
        color_set.add("green")
    elif 1200 <= a <= 1599:
        color_set.add("lightblue")
    elif 1600 <= a <= 1999:
        color_set.add("blue")
    elif 2000 <= a <= 2399:
        color_set.add("yellow")
    elif 2400 <= a <= 2799:
        color_set.add("orange")
    elif 2800 <= a <= 3199:
        color_set.add("red")
    else:
        all += 1
print(max(len(color_set),1), all+len(color_set))
