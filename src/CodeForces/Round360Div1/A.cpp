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

/**
 * A. NP-Hard Problem
 * https://codeforces.com/contest/687/problem/A
 * 二部グラフ判定問題。グラフが連結でないことに注意する。
 */
int colors[100005];
bool is_bipartite_graph(const Graph &graph, int v, int c) {
    colors[v] = c;
    for (int u: graph[v]) {
        if (colors[u] == c) {
            return false;
        }
        if (colors[u] == 0 && !is_bipartite_graph(graph, u, -c)) {
            return false;
        }
    }
    return true;
}

void Main() {
    int N, M;
    cin >> N >> M;
    Graph graph(N);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool is_bipartite = true;
    rep(i, N) {
        if (colors[i] == 0) {
            if (!is_bipartite_graph(graph, i, 1)) {
                is_bipartite = false;
            }
        }
    }

    if (is_bipartite) {
        int a = 0;
        int b = 0;
        vector<int> A;
        vector<int> B;
        rep(i, N) {
            if (colors[i] == 1) {
                a ++;
                A.push_back(i+1);
            }else if(colors[i] == -1) {
                b ++;
                B.push_back(i+1);
            }
        }
        cout << a << '\n';
        rep(i, a) {
            cout << A[i] << ' ';
        }
        cout << '\n';
        cout << b << '\n';
        rep(i, b) {
            cout << B[i] << ' ';
        }
        cout << '\n';
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
