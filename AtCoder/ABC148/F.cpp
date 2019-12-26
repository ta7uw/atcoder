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
 * F - Playing Tag on Tree
 * https://atcoder.jp/contests/abc148/tasks/abc148_f
 *
 * 高橋君が青木君より先に到達することができるような葉のうち、青木君から最も遠いものを求める。
 * bfs や dfs を使えばよい
 */
void Main() {
    int N, u, v;
    cin >> N >> u >> v;
    u--;
    v--;
    Graph graph(N);
    rep(i, N-1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    if (graph[u].size() == 1 && graph[u][0] == v) {
        cout << 0 << '\n';
        return;
    }
    vector<int> T(N, -1), S(N, -1);

    queue<P> que;
    que.push({v, 0});
    S[v] = 0;
    while (!que.empty()) {
        P p = que.front();
        que.pop();
        for (int to : graph[p.first]) {
            if (S[to] == -1) {
                S[to] = p.second + 1;
                que.push({to, S[to]});
            }
        }
    }

    que.push({u, 0});
    T[u] = 0;
    while (!que.empty()) {
        P p = que.front();
        que.pop();
        for (int to : graph[p.first]) {
            if (T[to] == -1) {
                T[to] = p.second + 1;
                que.push({to, T[to]});
            }
        }
    }
    int ans = 0;
    rep(i, N) {
        if (S[i] > T[i]) {
            ans = max(ans, S[i]);
        }
    }
    cout << ans - 1<< '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
