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

s_list = []
h, w = map(int, input().split())
for i in range(h):
    s_list.append(input())

route = [dict() for _ in range(h*w)]
all_white = 0
for i in range(h):
    for j in range(w):
        if s_list[i][j] == "#":
            continue
        else:
            all_white += 1
        if i != h-1 and s_list[i+1][j] == ".":
            route[w*i+j][w*(i+1)+j] = 1
        if j != w-1 and s_list[i][j+1] == ".":
            route[w*i+j][w*i+j+1] = 1
        if i != 0 and s_list[i-1][j] == ".":
            route[w*i+j][w*(i-1)+j] = 1
        if j != 0 and s_list[i][j-1] == ".":
            route[w*i+j][w*i+j-1] = 1

di = Dijkstra(route, 0, h*w-1)
r = di.execute()
count = len(r)
if count > 1:
    print(all_white-count)
else:
    print(-1)