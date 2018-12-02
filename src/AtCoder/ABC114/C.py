N = int(input())

length = len(str(N))
reuslt = 0
r_list = []

if length <= 2:
    print(0)
    exit()

def search(now, lastNum):
    if lastNum == 0:
        r_list.append(now)
        return
    search(now + "3", lastNum - 1)
    search(now + "5", lastNum - 1)
    search(now + "7", lastNum - 1)


for i in range(length-2):
    search("", length-i)
count = 0
for r in r_list:
    num = int(r)
    if num <= N and (r.count("7") >= 1 and r.count("5") >= 1 and r.count("3") >= 1):
        count += 1
print(count)