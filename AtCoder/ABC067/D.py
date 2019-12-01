import heapq


class Dijkstra:

    def __init__(self, rote_map, start_point, goal_point=None):
        self.rote_map = rote_map
        self.start_point = start_point
        self.goal_point = goal_point

    def execute(self):
        num_of_city = len(self.rote_map)
        dist = [float("inf") for _ in range(num_of_city)]
        prev = [float("inf") for _ in range(num_of_city)]

        dist[self.start_point] = 0
        heap_q = []
        heapq.heappush(heap_q, (0, self.start_point))
        route_count = [0 for _ in range(num_of_city)]
        route_count[self.start_point] = 1
        while len(heap_q) != 0:
            prev_cost, src = heapq.heappop(heap_q)

            if dist[src] < prev_cost:
                continue

            for dest, cost in self.rote_map[src].items():
                if cost != float("inf") and dist[dest] > dist[src] + cost:
                    dist[dest] = dist[src] + cost
                    heapq.heappush(heap_q, (dist[dest], dest))
                    prev[dest] = src
                if dist[dest] == dist[src] + cost:
                    route_count[dest] += route_count[src]

        if self.goal_point is not None:
            return self._get_path(self.goal_point, prev)
        else:
            return dist, route_count

    def _get_path(self, goal, prev):
        path = [goal]
        dest = goal

        while prev[dest] != float("inf"):
            path.append(prev[dest])
            dest = prev[dest]

        return list(reversed(path))


N = int(input())
graph = [dict() for _ in range(N)]
for _ in range(N - 1):
    a, b = map(int, input().split())
    graph[a - 1][b - 1] = 1
    graph[b - 1][a - 1] = 1

path = Dijkstra(graph, 0, N - 1).execute()
cost = len(path) - 1

black = 1
if cost % 2 == 0:
    tmp = (cost - 1) // 2
    black += tmp + 1
else:
    tmp = (cost - 1) // 2
    black += tmp
not_path = set(path[black:])
visited = [False for _ in range(N)]
q = [0]
visited[0] = False
while len(q) != 0:
    dist = q.pop()
    for d in graph[dist].keys():
        if visited[d] or d in not_path:
            continue
        q.append(d)
        visited[d] = True
for p in tuple(path):
    visited[p] = False
for v in visited:
    if v:
        black += 1
white = N - black
if black > white:
    print("Fennec")
else:
    print("Snuke")
