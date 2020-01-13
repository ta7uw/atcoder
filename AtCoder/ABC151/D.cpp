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

ll to_id(ll x, ll y) {
    return 25 * x + y;
}

/**
 * D - Maze Master
 * https://atcoder.jp/contests/abc151/tasks/abc151_d
 *
 * ワーシャルフロイドで全点間最短距離を求める
 * スタートとゴールが同じ場合のケースをスキップすることを忘れない。
 * 1 2
 * ..
 * のようなケース
 */
void Main() {
    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    rep(i, H) cin >> grid[i];

    Graph graph(500, vector<ll>(500, INF));
    rep(i, H) {
        rep(j, W) {
            if (grid[i][j] == '#') continue;
            rep(k, 4) {
                int x = dx[k];
                int y = dy[k];
                if (0 <= j + y && j + y < W && 0 <= i + x && i + x < H && grid[i + x][j + y] != '#') {
                    ll from = to_id(i, j);
                    ll to = to_id(i + x, j + y);
                    graph[from][to] = 1;
                }
            }
        }
    }
    warshall_floyd(graph);
    ll ans = 0;
    rep(i, H) {
        rep(j, W) {
            ll start = to_id(i, j);
            if (grid[i][j] == '#') continue;
            rep(i2, H) {
                rep(j2, W) {
                    ll goal = to_id(i2, j2);
                    if (start == goal)continue;
                    if (grid[i2][j2] == '#') continue;
                    ll tmp = graph[start][goal];
                    if (tmp < INF) {
                        ans = max(tmp, ans);
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
