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

int colors[205];
bool is_bipartite_graph(const Graph & graph, int v, int c) {
    colors[v] = c;
    for (int u: graph[v]) {
        if (colors[u] == c) {
            return false;
        }
        if (colors[u] == 0 && ! is_bipartite_graph(graph, u, -c)) {
            return false;
        }
    }
    return true;
}

void warshall_floyd(Graph &graph) {
    int V = graph.size();
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

/**
 * B - Graph Partition
 * https://atcoder.jp/contests/agc039/tasks/agc039_b
 * 二部グラフ判定 + ワーシャルフロイド法
 * 二部グラフであれば条件を満たすことができる。
 * 条件を満たす場合は +1 するように集合をもたせることができるので木の直径を求める。
 * 制約からワーシャルフロイドで間に合う
 */
void Main() {
    int N;
    cin >> N;
    Graph graph(N);
    Graph dist(N, vector<ll>(N, INF));
    rep(i, N) {
        string s;
        cin >> s;
        rep(j, N) {
            if (s[j] == '1') {
                graph[i].push_back(j);
                dist[i][j] = 1;
            }
        }
    }
    if (is_bipartite_graph(graph, 0, 1)) {
        warshall_floyd(dist);
        ll ans = 0;
        rep(i, N) {
            rep(j, i) {
                ans = max(ans, dist[i][j]);
            }
        }
        cout << ans + 1<< '\n';
    }else{
        cout << -1 << '\n';
    }

}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
