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


/**
 * E - Travel by Car
 * https://atcoder.jp/contests/abc143/tasks/abc143_e
 *
 * ワーシャルフロイド法
 * ワーシャルフロイド法を２回使う
 * 全点対最短経路を求めたあと 新しいグラフをつくる。
 * 任意の頂点間で L 以下で到達できる場合新しいグラフにコスト1の辺を追加していく。
 * 新しいグラフにおいて再度ワーシャルフロイド法を使うと燃料の補給回数が求められる
 */
void Main() {
    int N, M, L;
    cin >> N >> M >> L;
    Graph graph(N, vector<ll>(N, INF));
    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        if (c > L) continue;
        graph[a][b] = c;
        graph[b][a] = c;
    }
    warshall_floyd(graph);
    Graph graph1(N, vector<ll>(N, INF));
    rep(i, N) {
        rep(j, N) {
            if (i == j) continue;
            if (graph[i][j] <= L) graph1[i][j] = 1;
        }
    }
    warshall_floyd(graph1);
    int Q;
    cin >> Q;
    rep(q, Q) {
        int s, t;
        cin >> s >> t;
        s--;
        t--;
        ll d = graph1[s][t];
        if (d == INF) {
            cout << -1 << '\n';
        } else {
            cout << d - 1<< '\n';
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
