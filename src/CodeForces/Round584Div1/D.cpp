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
struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<int> size;
    vector<vector<int>> group;

    UnionFind(int n = 1) {
        init(n);
    }

    void init(int n = 1) {
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

    bool merge(int x, int y) {
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

    void merge_tech(int x, int y) {
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


void Main() {
    int N, K;
    cin >> N >> K;
    UnionFind unionFind(N);
    int t = -1;
    rep(i, K){
        int a, b;
        cin >> a >> b;
        unionFind.merge(a, b);
    }

    unordered_set<int> used;
    int ans = K;
    rep2(i, 1, N+1) {
        if (used.find(unionFind.find(i)) == used.end() && unionFind.get_size(i) > 1) {
            ans -= unionFind.get_size(i) - 1;
            used.insert(unionFind.find(i));
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
