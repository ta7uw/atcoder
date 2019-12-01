#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;i++)
#define rep2(i, m, n) for(int i=m;i<n;i++)
#define rrep(i, n, m) for(int i=n;i>=m;i--)
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll MOD = 1000000007;
#ifdef __DEBUG

#include "cpp-pyprint/pyprint.h"

#endif

void dfs2(Graph &g, vector<ll> &cnt, int start,  int tar, vector<int>& plus, int t) {
    cnt[tar] += plus[tar] + t;
    for (auto &v: g[tar]) {
        if (v == start) continue;
        dfs2(g, cnt, tar, v, plus, cnt[tar]);
    }
}

void Main() {
    int N, Q;
    cin >> N >> Q;
    Graph G(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);

    }
    vector<ll> cnt(N, 0);
    vector<int> plus(N, 0);
    for (int i = 0; i < Q; ++i) {
        int p, x;
        cin >> p >> x;
        p--;
        plus[p] += x;
    }
    dfs2(G, cnt,   -1, 0, plus, 0);
    for (int i = 0; i < N; ++i) {
        cout << cnt[i] << " ";
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
