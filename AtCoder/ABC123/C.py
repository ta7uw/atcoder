N = int(input())
A = int(input())
B = int(input())
C = int(input())
D = int(input())
E = int(input())
import math

print(math.ceil(max(N / A, N / B, N / C, N / D, N / E)) + 4)
