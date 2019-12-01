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

class UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<int> size;
    vector<vector<int>> group;
public:
    UnionFind(int n = 1) {
        par.resize(n + 1);
        rank.resize(n + 1);
        size.resize(n + 1);
        group.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            par[i] = i;
            rank[i] = 0;
            size[i] = 1;
            group[i].push_back(i);
        }
    }

    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            int r = find(par[x]);
            return par[x] = r;
        }
    }

    bool is_same(int x, int y) {
        return find(x) == find(y);
    }

    bool unit(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        } else {
            if (rank[x] < rank[y]) {
                swap(x, y);
            }
            if (rank[x] == rank[y]) {
                ++rank[x];
            }
            par[y] = x;
            size[x] += size[y];
            return true;
        }
    }

    int get_size(int x) {
        return size[find(x)];
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (group[x].size() > group[y].size()) {
            swap(x, y);
        }
        copy(group[y].begin(), group[y].end(), back_inserter(group[x]));
        group[y].clear();
        par[y] = x;
    }
};

/**
 * B - ナップサック問題
 * https://atcoder.jp/contests/kupc2019/tasks/kupc2019_b
 *
 * UnionFindで商品をグルーピングして合成した商品を使って01ナップザック問題をとく
 */
void Main() {
    int N, M, W;
    cin >> N >> M >> W;
    vector<P> items(N);
    rep(i, N) cin >> items[i].first >> items[i].second;
    UnionFind unionFind(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        unionFind.unit(a, b);
    }
    unordered_map<ll, P> new_items;
    rep(i, N) {
        int par = unionFind.find(i + 1);
        if (new_items.find(par) == new_items.end()) {
            new_items[par] = make_pair(items[i].first, items[i].second);
        } else {
            P p = new_items[par];
            p.first += items[i].first;
            p.second += items[i].second;
            new_items[par] = p;
        }
    }
    items.resize(0);
    for (auto x: new_items) {
        items.push_back(x.second);
    }
    int n = items.size();
    vector<vector<ll>> dp(n + 1 , vector<ll>(W + 1, 0));
    rep(i, n) {
        rep(j, W+1) {
            if (j - items[i].first >= 0) {
                dp[i + 1][j] = max(dp[i][j - items[i].first] + items[i].second, dp[i + 1][j]);
            }
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }
    }
    cout << dp[n][W] << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
