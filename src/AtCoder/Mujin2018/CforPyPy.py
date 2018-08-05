import numpy as np
N, M = map(int, input().split())

count = [[ [0 for j in range(M)] for i in range(N)] for m in range(4)]
#count = list(np.zeros([4, N, M]))
mp = [ [False] * M for i in range(N)]
for i in range(N):
    line = input()
    for j in range(M):
        if line[j] == "#":
            mp[i][j] =True

for i in range(N):
    for j in range(M):
        if mp[i][j]: 
          continue
        else :
        	count[0][i][j] = (0 if i == 0 else count[0][i-1][j]) + 1
        	count[3][i][j] = (0 if j == 0 else count[3][i][j-1]) +1

for i in range(N-1, -1 , -1):
     for j in range(M-1, -1, -1):
         if mp[i][j]:
          continue
         else :
         	count[1][i][j] = (0 if j == M-1 else count[1][i][j+1]) + 1
         	count[2][i][j] = (0 if i == N-1 else count[2][i+1][j]) + 1

answer = 0
for i in range(N):
    for j in range(M):
        if mp[i][j]: 
          continue
        answer  += (count[2][i][j] + count[0][i][j]-2) * (count[1][i][j] + count[3][i][j]-2)
print(answer)
