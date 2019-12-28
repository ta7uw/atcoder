#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
#ifdef __DEBUG

/**
 * For DEBUG
 * https://github.com/ta7uw/cpp-pyprint
 */
#include "cpp-pyprint/pyprint.h"

#endif

struct edge {
    int from, to;
    ll cost;
};

class Dijkstra {
    int V;
    vector<vector<edge>> edges;
    vector<ll> dist;
    vector<ll> prev;
    vector<ll> route_count;

public:
    Dijkstra(int v) : V(v) {
        edges.resize(V);
        dist.resize(V, INF);
        prev.resize(V, INF);
        route_count.resize(V, 0);
    }

    void add_edge(int from, int to, ll cost) {
        edges[from].push_back({from, to, cost});
    }

    /**
     * @param goal 0-indexed
     * @return return cost to reach the goal. return INF if the goal is unreachable.
     */
    ll get_cost(int goal) {
        return dist[goal];
    }

    /**
     * @param goal 0-indexed
     * @return return total route count to reach the goal ( result value % MOD )
     */
    ll get_route_count(int goal) {
        return route_count[goal];
    }

    /**
     * @param goal 0-indexed
     * @return return route from start to goal
     */
    vector<ll> get_route(int goal) {
        vector<ll> res;
        res.push_back(goal);
        ll dest = goal;
        while (prev[goal] != INF) {
            res.push_back(prev[goal]);
            dest = prev[goal];
        }
        reverse(res.begin(), res.end());
        return res;
    }

    void exec(int start) {
        dist[start] = 0;
        route_count[start] = 1;
        priority_queue<P, vector<P>, greater<>> queue;
        queue.push({dist[start], start});
        while (!queue.empty()) {
            P p = queue.top();
            queue.pop();
            ll prev_cost = p.first;
            ll src = p.second;
            if (dist[src] < prev_cost) continue;

            for (edge &e : edges[src]) {
                ll to = e.to;
                ll cost = e.cost;
                if (cost != INF && dist[to] > dist[src] + cost) {
                    dist[to] = dist[src] + cost;
                    queue.push({dist[to], to});
                    prev[to] = src;
                    route_count[to] = route_count[src];
                }else if (dist[to] == dist[src] + cost) {
                    route_count[to] += route_count[src];
                    route_count[to] %= MOD;
                }
            }
        }
    }
};

/**
 * E - Avoiding Collision
 * https://atcoder.jp/contests/arc090/submissions/9169594
 *
 * 2人が経路上で出会うことも含めた最短経路の選び方から
 * 2人が頂点 v 、もしくは辺上で出会った選び方を引けばよい
 */
void Main() {
    int N, M, S, T;
    cin >> N >> M >> S >> T;
    Dijkstra t(N), a(N);
    vector<vector<P>> graph(N);
    rep(i, M) {
        int u, v, d;
        cin >> u >> v >> d;
        u--;
        v--;
        t.add_edge(u, v, d);
        a.add_edge(u, v, d);
        t.add_edge(v, u, d);
        a.add_edge(v, u, d);
        graph[u].emplace_back(v, d);
        graph[v].emplace_back(u, d);
    }
    t.exec(S - 1);
    a.exec(T - 1);
    ll X = t.get_route_count(T - 1);
    ll Y = a.get_route_count(S - 1);
    ll ans = X * Y;
    ans %= MOD;
    ll cost = t.get_cost(T - 1);
    rep(i, N) {
        if (t.get_cost(i) == a.get_cost(i) && t.get_cost(i) + a.get_cost(i) == cost) {
            ll sub = t.get_route_count(i) * a.get_route_count(i);
            sub %= MOD;
            sub *= sub;
            sub %= MOD;
            ans -= sub;
            ans %= MOD;
            if (ans < 0) ans += MOD;
        }
        ll from = i;
        for (P p : graph[i]) {
            ll d = p.second;
            ll to = p.first;
            if (t.get_cost(from) + d + a.get_cost(to) != cost) continue;
            if (t.get_cost(from) < a.get_cost(from) && t.get_cost(to) > a.get_cost(to)) {
                ll sub = t.get_route_count(from) * a.get_route_count(to);
                sub %= MOD;
                sub *= sub;
                sub %= MOD;
                ans -= sub;
                ans %= MOD;
                if (ans < 0) ans += MOD;
            }
        }
    }
    cout << ans % MOD << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
