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
        route_count = [0 for _ in range(n)]
        route_count[self.start_point] = 1
        while len(heap_q) != 0:
            prov_cost, src = heapq.heappop(heap_q)

            if dist[src] < prov_cost:
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


n = int(input())
a, b = map(int, input().split())
m = int(input())
x_list = []
y_list = []
for i in range(m):
    x, y = map(int, input().split())
    x_list.append(x)
    y_list.append(y)

route_map = [dict() for _ in range(n)]
for i in range(m):
    x, y = x_list[i], y_list[i]
    route_map[x - 1][y - 1] = 1
    route_map[y - 1][x - 1] = 1
dijkstra_result, route_count = Dijkstra(route_map, a - 1).execute()
print(route_count[b-1]% (10 ** 9 + 7))


