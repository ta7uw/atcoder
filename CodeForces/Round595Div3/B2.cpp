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
 * B2. Books Exchange (hard version)
 * https://codeforces.com/contest/1249/problem/B2
 *
 * グループ内で１周して帰ってくるのでグループの要素分の日数が必要。
 * よって UnionFind で同じグループの要素数を管理すればいい
 */
void Main() {
    int Q;
    cin >> Q;
    rep(q, Q) {
        int N;
        cin >> N;
        vector<int> P(N);
        rep(i, N) cin >> P[i];
        UnionFind unionFind(N);
        rep(i, N) {
            int p = P[i];
            p--;
            unionFind.unit(p, i);
        }
        rep(i, N) {
            cout << unionFind.get_size(i) << ' ';
        }
        cout << '\n';
    }

}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
