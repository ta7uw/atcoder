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
 * E. Nearest Opposite Parity
 * https://codeforces.com/contest/1272/problem/E
 * i から　i + a, i - a に辺を貼った有向グラフを考える
 * 奇数をもつ頂点から偶数を持つ頂点までの距離がわかればよいので
 * 有向辺を反対向きにして bfs を行うことで最も近くにある偶数をもつ頂点までの距離が得られる
 * これを奇数、偶数に対して行って答えを得る
 */
void Main() {
    ll N;
    cin >> N;
    vector<ll> A(N), even, odd, ans(N, -1);
    rep(i, N) cin >> A[i];
    Graph graph(N);
    rep(i, N) {
        ll a = A[i];
        if (a & 1) {
            odd.push_back(i);
        } else {
            even.push_back(i);
        }
        if (i - a >= 0) {
            graph[i-a].push_back(i);
        }
        if (i + a < N) {
            graph[i+a].push_back(i);
        }
    }
    vector<ll> dist(N, INF);
    queue<ll> que;
    for (ll e : even) {
        que.push(e);
        dist[e] = 0;
    }
    while (!que.empty()) {
        ll p = que.front();
        que.pop();
        for (ll v : graph[p]) {
            if (dist[v] == INF) {
                dist[v] = dist[p] + 1;
                que.push(v);
            }
        }
    }
    for (ll o : odd) {
        if (dist[o] != INF) {
            ans[o] = dist[o];
        }
    }

    dist.assign(N, INF);
    for (ll v : odd) {
        que.push(v);
        dist[v] = 0;
    }
    while (!que.empty()) {
        ll p = que.front();
        que.pop();
        for (ll v : graph[p]) {
            if (dist[v] == INF) {
                dist[v] = dist[p] + 1;
                que.push(v);
            }
        }
    }
    for (ll e : even) {
        if (dist[e] != INF) {
            ans[e] = dist[e];
        }
    }
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
