#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll, ll>;
using edge = pair<ll, P>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
using Graph = vector<vector<ll>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
#ifdef __DEBUG

#include "cpp-pyprint/pyprint.h"

#endif

void Main() {
    int N, M;
    cin >> N >> M;
    Graph graph(N);
    vector<int> in_cnt(N, 0);
    rep(i, N + M - 1) {
        int a, b;
        cin >> a >> b;
        a --;
        b --;
        graph[a].push_back(b);
        in_cnt[b] ++;
    }

    queue<int> que;
    rep(i, N) {
        if (in_cnt[i] == 0) {
            que.push(i);
        }
    }
    vector<int> sorted(N, -1);
    sorted[que.front()] = 0;
    while (!que.empty()) {
        int q = que.front(); que.pop();
        for (ll v : graph[q]) {
            in_cnt[v] --;
            if (in_cnt[v] == 0) {
                sorted[v] =  q + 1;
                que.push(v);
            }
        }
    }
    rep(i, N) {
        cout << sorted[i] << endl;
    }


}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
