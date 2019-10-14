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

bool has_3edges(const Graph &graph, int v, int prev) {
    if (graph[v].size() >= 3) {
        return false;
    }
    for (int u: graph[v]) {
        if (u == prev) {
            continue;
        }
        if (!has_3edges(graph, u, v)) {
            return false;
        }
    }
    return true;
}

int X[6][3] = {{1, 2, 0},
               {1, 2, 0},
               {1, 2, 0},
               {2, 0, 1},
               {2, 0, 1},
               {2, 0, 1}};

ll dfs(const Graph &graph, vector<vector<ll>> &C, int v, int prev, int c, int porm) {
    ll res = C[c][v];
    for (ll u : graph[v]) {
        if (u == prev) continue;
        res += dfs(graph, C, u, v, X[porm][c], porm);
    }
    return res;
}

void dfs2(const Graph &graph, vector<vector<ll>> &C, int v, int prev, int c, int porm, vector<int> &ans) {
    ans[v] = c + 1;
    for (ll u : graph[v]) {
        if (u == prev) continue;
        dfs2(graph, C, u, v, X[porm][c], porm, ans);
    }
}

/**
 * D. Paint the Tree
 * https://codeforces.com/contest/1244/problem/D
 *
 * 木が3本辺を持つ場合達成不可。
 * それ以外の場合は1本しか辺をもたないところをスタート地点として
 * 6通りの遷移をすべて試す
 */
void Main() {
    int N;
    cin >> N;
    vector<vector<ll>> C(3, vector<ll>(N, 0));
    rep(i, N) cin >> C[0][i];
    rep(i, N) cin >> C[1][i];
    rep(i, N) cin >> C[2][i];
    Graph graph(N);
    rep(i, N - 1) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    if (!has_3edges(graph, 0, -1)) {
        cout << -1 << '\n';
        return;
    }
    int start = -1;
    rep(i, N) {
        if (graph[i].size() == 1) {
            start = i;
            break;
        }
    }
    vector<P> ta(6);
    rep(i, 6) {
        ta[i] = make_pair(dfs(graph, C, start, -1, i % 3, i), i);
    }
    P t = *min_element(ta.begin(), ta.end());
    cout << t.first << '\n';
    vector<int> ans(N);
    dfs2(graph, C, start, -1, t.second % 3, t.second, ans);
    rep(i, N) {
        cout << ans[i] << ' ';
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
