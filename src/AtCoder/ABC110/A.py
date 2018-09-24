ABC = list(map(int, input().split()))
ABC.sort()

print(int(str(ABC[2]) + str(ABC[1])) + ABC[0])

