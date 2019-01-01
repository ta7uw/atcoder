class BellmanFord:
    def __init__(self, graph, num_v, start_point):
        self.num_v = num_v
        self.graph = graph
        self.start_point = start_point

    def execute(self):
        dist = [float("inf") for _ in range(self.num_v)]
        dist[self.start_point] = 0
        negative = [False for _ in range(self.num_v)]
        for i in range(self.num_v - 1):
            for src, dest, cost in self.graph:
                if dist[dest] > dist[src] + cost:
                    dist[dest] = dist[src] + cost
        for i in range(self.num_v):
            for src, dest, cost in self.graph:
                if dist[dest] > dist[src] + cost:
                    dist[dest] = dist[src] + cost
                    negative[dest] = True
                if negative[src]:
                    negative[dest] = True
        return dist, negative


n, m = map(int, input().split())
graph = []

for i in range(m):
    a, b, c = map(int, input().split())
    graph.append([a - 1, b - 1, -c])
bellman = BellmanFord(graph, n, 0)
result, negative = bellman.execute()

if negative[-1]:
    print("inf")
else:
    print(-result[-1])
