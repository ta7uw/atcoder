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

public:
    Dijkstra(int v) : V(v) {
        edges.resize(V);
        dist.resize(V, INF);
        prev.resize(V, INF);
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

    void exec(int start) {
        dist[start] = 0;
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
                }
            }
        }
    }
};

/**
 * D - Shortest Path on a Line
 * https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_d
 *
 * 各 i に対して頂点 i + 1 から頂点 i に長さ 0 の辺を追加し,
 * L から R へコスト C の辺を貼ると Dijkstra 法で解ける。
 */

void Main() {
    int N, M;
    cin >> N >> M;
    Dijkstra dijkstra(N);
    rep(i, M) {
        ll l, r, c;
        cin >> l >> r >> c;
        l--;
        r--;
        dijkstra.add_edge(l, r, c);
    }
    rep2(i, 1, N) {
        dijkstra.add_edge(i, i - 1, 0);
    }

    dijkstra.exec(0);

    ll ans = dijkstra.get_cost(N - 1);

    if (ans != INF) {
        cout << ans << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
