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

template<typename T>
struct edge {
    int from, to;
    T cost;
};

template<typename T>
vector<T> kruskal(vector<edge<T>> &edges, int V) {
    sort(edges.begin(), edges.end(), [](const edge<T> &a, const edge<T> &b) {
        return a.cost > b.cost;
    });
    UnionFind unionFind(V);
    vector<ll> res;
    for (edge<T> &e: edges) {
        if (unionFind.unit(e.to, e.from)) {
            res.push_back(e.cost);
        }
    }
    return res;
}

/**
 * D - 楽しすぎる家庭菜園
 * https://atcoder.jp/contests/iroha2019-day2/tasks/iroha2019_day2_d
 * クラスカル法を改良する。辺を昇順ではなく降順でソートして貪欲に見て行く
 * コストの総和ではなく、コストをもつことで番号を復元できるようにする。
 */
void Main() {
    int N, M;
    cin >> N >> M;
    vector<edge<ll>> graph;
    unordered_map<ll, int> map;
    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        graph.push_back({a, b, c});
        map[c] = i + 1;
    }
    vector<ll> res = kruskal(graph, N);
    vector<ll> ans;
    rep(i, res.size()) {
        ans.push_back(map[res[i]]);
    }
    sort(ans.begin(), ans.end());
    rep(i, ans.size()) {
        cout << ans[i] << '\n';
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
