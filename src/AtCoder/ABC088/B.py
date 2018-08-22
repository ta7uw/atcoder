N = int(input())
a_list = [a for a in map(int, input().split())]
a_list.sort()
a_list.reverse()
alice = 0
bob = 0

for i in range(N):
    if i % 2 == 0:
        alice += a_list[i]
    else:
        bob += a_list[i]
print(alice-bob)
