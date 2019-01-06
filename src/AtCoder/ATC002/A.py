R, C = map(int, input().split())
start = list(map(int, input().split()))
goal = list(map(int, input().split()))
graph = [[] for _ in range(R)]
for i in range(R):
    tmp = list(input())
    graph[i] = tmp

visited = [[False for _ in range(C)] for _ in range(R)]
dist = [[0 for _ in range(C)] for _ in range(R)]


def bfs(start_r, start_c):
    q = [[start_r, start_c]]
    visited[start_r][start_c] = True
    while len(q) != 0:
        next_p = q.pop(0)
        r, c = next_p

        if r + 1 < R and not visited[r + 1][c] and graph[r + 1][c] == ".":
            q.append([r + 1, c])
            dist[r + 1][c] = dist[r][c] + 1
            visited[r + 1][c] = True
        if r - 1 > 0 and not visited[r - 1][c] and graph[r - 1][c] == ".":
            q.append([r - 1, c])
            dist[r - 1][c] = dist[r][c] + 1
            visited[r - 1][c] = True
        if c + 1 < C and not visited[r][c + 1] and graph[r][c + 1] == ".":
            q.append([r, c + 1])
            dist[r][c + 1] = dist[r][c] + 1
            visited[r][c + 1] = True
        if c - 1 > 0 and not visited[r][c - 1] and graph[r][c - 1] == ".":
            q.append([r, c - 1])
            dist[r][c - 1] = dist[r][c] + 1
            visited[r][c - 1] = True


bfs(start[0] - 1, start[1] - 1)
print(dist[goal[0] - 1][goal[1] - 1])
