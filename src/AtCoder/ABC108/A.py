K = int(input())
 
odd = [i for i in range(1, K+1) if i % 2 != 0]
even = [i for i in range(1, K+1) if i % 2 == 0]
 
print(len(odd) * len(even))
