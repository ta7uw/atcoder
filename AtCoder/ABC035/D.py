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


N, M, T = map(int, input().split())
a_list = list(map(int, input().split()))
graph = [dict() for _ in range(N + 1)]
rev_graph = [dict() for _ in range(N + 1)]
for _ in range(M):
    a, b, c = map(int, input().split())
    graph[a][b] = c
    rev_graph[b][a] = c

graph, _ = Dijkstra(graph, 1).execute()
rev_graph, _ = Dijkstra(rev_graph, 1).execute()

ans = a_list[0] * T
for i in range(2, N + 1):
    des = graph[i]
    res = rev_graph[i]
    ans = max(ans, a_list[i - 1] * (T - des - res))
print(ans)
