N = int(input())
a_list = map(int, input().split())

count = {}
for a in a_list:
    if a not in count.keys():
        count[a] = 1
    else:
        count[a] += 1

result = 0
for item, item_count in count.items():
    if item <= item_count:
        result += item_count - item
    else:
        result += item_count

print(result)
