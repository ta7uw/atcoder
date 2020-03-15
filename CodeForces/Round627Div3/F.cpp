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

vector<ll> dp;
Graph graph;
vector<ll> A;
vector<ll> ans;

void dfs(ll v, ll prev) {
    for (ll u : graph[v]) {
        if (u != prev) {
            dfs(u, v);
        }
    }
    if (A[v] == 1) {
        dp[v] = 1;
    } else {
        dp[v] = -1;
    }
    for (ll u : graph[v]) {
        if (u != prev) {
            if (dp[u] > 0) {
                dp[v] += dp[u];
            }
        }
    }
}

void dfs2(ll v, int prev) {
    ans[v] = dp[v];
    for (ll u : graph[v]) {
        if (u != prev) {
            if (dp[u] > 0) dp[v] -= dp[u];
            if (dp[v] > 0) dp[u] += dp[v];
            dfs2(u, v);
            if (dp[v] > 0) dp[u] -= dp[v];
            if (dp[u] > 0) dp[v] += dp[u];
        }
    }
}

void Main() {
    ll N;
    cin >> N;
    dp.resize(N, -INF);
    A.resize(N);
    ans.resize(N);
    rep(i, N) cin >> A[i];
    graph.resize(N);
    rep(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(0, -1);
    dfs2(0, -1);
    rep(i, N) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
