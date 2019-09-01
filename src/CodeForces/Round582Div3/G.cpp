#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll, ll>;
using edge = pair<ll, P>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
using Graph = vector <vector<ll>>;
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
    vector <vector<int>> group;

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
    int N, M;
    cin >> N >> M;
    priority_queue <edge, vector<edge>, greater<>> graph;
    rep(i, N - 1) {
        int u, v, e;
        cin >> u >> v >> e;
        u--;
        v--;
        graph.push(make_pair(e, make_pair(u, v)));
    }
    vector <P> query(M);
    rep(i, M) {
        cin >> query[i].first;
        query[i].second = i;
    }
    sort(query.begin(), query.end());
    UnionFind unionFind(N);

    vector <ll> ans(M);
    ll cnt = 0;
    rep(i, M) {
        P q = query[i];
        while (!graph.empty() && graph.top().first <= q.first) {
            edge e = graph.top();
            graph.pop();
            cnt -= (ll) unionFind.get_size(e.second.first) * (unionFind.get_size(e.second.first) - 1) / 2;
            cnt -= (ll) unionFind.get_size(e.second.second) * (unionFind.get_size(e.second.second) - 1) / 2;
            unionFind.merge(e.second.first, e.second.second);
            cnt += (ll) unionFind.get_size(e.second.first) * (unionFind.get_size(e.second.first) - 1) / 2;
        }
        ans[q.second] = cnt;
    }
    rep(i, M) {
        cout << ans[i] << " ";
    }
    cout << endl;

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
