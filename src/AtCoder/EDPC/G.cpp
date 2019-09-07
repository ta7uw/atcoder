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

class DAG {
    int N;
    Graph graph;
    vector<int> visited;

    void dfs(int v) {
        if (visited[v] == 2) {
            is_acyclic = false;
            return;
        }
        if (!visited[v]) {
            visited[v] = 2;
            for (int tar : graph[v]) {
                dfs(v);
            }
            visited[v] = 1;
            sorted.push_back(v);
        }
    }

public:
    vector<int> sorted;

    DAG(int N) : N(N), graph(N), visited(N) {}

    DAG(Graph &graph) : N(graph.size()), graph(graph), visited(graph.size()) {}

    bool is_acyclic = true;

    void add_edge(int a, int b) {
        graph[a].push_back(b);
    }

    void topological_sort() {
        for (int i = 0; i < N; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        reverse(sorted.begin(), sorted.end());
    }
};

int longest_path(const Graph &graph) {
    int N = graph.size();

    Graph inv(N);
    for (int i = 0; i < N; ++i) {
        for (int v: graph[i]) {
            inv[v].push_back(i);
        }
    }
    vector<int> path_len(N, -1);
    function<void(int)> set_len = [&](int v) {
        if (path_len[v] != -1) {
            return;
        }
        if (inv[v].empty()) {
            path_len[v] = 0;
            return;
        }
        int max_num = 0;
        for (int tar : inv[v]) {
            set_len(tar);
            max_num = max(max_num, path_len[tar]);
        }
        path_len[v] = max_num + 1;

    };
    for (int i = 0; i < N; ++i) {
        set_len(i);
    }
    return *max_element(path_len.begin(), path_len.end());
}


void Main() {
    int N, M;
    cin >> N >> M;
    Graph graph(N);
    rep(i, M) {
        int x, y;
        cin >> x >> y;
        x --;
        y --;
        graph[x].push_back(y);
    }
    cout << longest_path(graph) << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
