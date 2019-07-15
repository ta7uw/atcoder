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

ll dfs(const Graph& g, int from , int now, int K) {
    int mul = 0;
    ll ans = 1;
    if (from == -1) {
        mul = K -1;
    }else{
        mul = K -2;
    }
    if (K < g[now].size()) {
        return 0;
    }else{
        for (auto v : g[now]) {
            if (v == from) {
                continue;
            }
            ans *= mul;
            ans %= MOD;
            mul -= 1;
            ans *= dfs(g, now, v, K);
            ans %= MOD;
        }
    }
    return ans;
}

void Main() {
    int N, K;
    cin >> N >> K;
    Graph graph;
    graph.assign(N, vector<int>());
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    ll ans = dfs(graph,-1, 0, K);
    cout << ans * K % MOD << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
