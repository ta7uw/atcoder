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
        while len(heap_q) != 0:
            prov_cost, src = heapq.heappop(heap_q)

            if dist[src] < prov_cost:
                continue

            for dest, cost in self.rote_map[src].items():
                if cost != float("inf") and dist[dest] > dist[src] + cost:
                    dist[dest] = dist[src] + cost
                    heapq.heappush(heap_q, (dist[dest], dest))
                    prev[dest] = src
        if self.goal_point is not None:
            return self._get_path(self.goal_point, prev)
        else:
            return dist

    def _get_path(self, goal, prev):
        path = [goal]
        dest = goal

        while prev[dest] != float("inf"):
            path.append(prev[dest])
            dest = prev[dest]

        return list(reversed(path))


n, m = map(int, input().split())
a_list = []
b_list = []
for i in range(m):
    a, b = map(int, input().split())
    a_list.append(a)
    b_list.append(b)

friends = [dict() for _ in range(n)]
for i in range(m):
    a, b = a_list[i]-1, b_list[i]-1
    friends[a][b] = 1
    friends[b][a] = 1

for i in range(n):
    dijkstra = Dijkstra(friends, i)
    r = dijkstra.execute()
    count = 0

    for x in r:
        if x == 2:
            count += 1
    print(count)



