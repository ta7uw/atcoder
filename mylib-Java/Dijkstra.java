import java.util.*;

public class Dijkstra {
    private int startPoint;
    private int goalPoint;
    private List<Map<Integer, Integer>> routeMap;
    private int[] routeCount;
    private int[] prev;


    Dijkstra(List<Map<Integer, Integer>> routeMap, int startPoint) {
        this.startPoint = startPoint;
        this.routeMap = routeMap;
        this.goalPoint = -1;

    }

    Dijkstra(List<Map<Integer, Integer>> routeMap, int startPoint, int goalPoint) {
        this.startPoint = startPoint;
        this.routeMap = routeMap;
        this.goalPoint = goalPoint;

    }

    private int getRouteCount() {
        return this.routeCount[this.goalPoint];
    }

    public List<Integer> getPath() {
        List<Integer> path = new ArrayList<>();
        int dest = this.goalPoint;
        path.add(this.goalPoint);
        while (this.prev[dest] != Integer.MAX_VALUE) {
            path.add(prev[dest]);
            dest = prev[dest];
        }
        Collections.reverse(path);
        return path;
    }

    public int[] execute() {
        int numberOfCity = this.routeMap.size();
        int[] dist = new int[numberOfCity];
        this.prev = new int[numberOfCity];
        this.routeCount = new int[numberOfCity];
        for (int i = 0; i < numberOfCity; i++) {
            dist[i] = Integer.MAX_VALUE;
            this.prev[i] = Integer.MAX_VALUE;
            this.routeCount[i] = 0;
        }
        dist[this.startPoint] = 0;
        this.routeCount[this.startPoint] = 1;
        PriorityQueue<Node> pQueue = new PriorityQueue<>();
        pQueue.offer(new Node(this.startPoint, 0));
        while (!pQueue.isEmpty()) {
            Node node = pQueue.poll();
            int prev_cost = node.getCost();
            int src = node.getNode();
            if (dist[src] < prev_cost) {
                continue;
            }
            for (Map.Entry<Integer, Integer> e : this.routeMap.get(src).entrySet()) {
                int dest = e.getKey();
                int cost = e.getValue();

                if (cost != Integer.MAX_VALUE && dist[dest] > dist[src] + cost) {
                    dist[dest] = dist[src] + cost;
                    this.prev[dest] = src;
                    pQueue.offer(new Node(dest, dist[dest]));
                }

                if (dist[dest] == dist[src] + cost) {
                    this.routeCount[dest] += this.routeCount[src];
                    this.routeCount[dest] %= 1000000007;
                }

            }
        }

        return dist;

    }

    class Node implements Comparable<Node> {
        private int node;
        private int cost;

        public Node(int node, int cost) {
            this.node = node;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node node2) {
            return Integer.compare(this.cost, node2.cost);
        }

        public int getNode() {
            return this.node;
        }

        public int getCost() {
            return this.cost;
        }
    }

}

