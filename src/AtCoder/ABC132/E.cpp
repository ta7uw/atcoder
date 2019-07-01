#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>

using namespace std;

const int MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;i++)
#define rep2(i, m, n) for(int i=m;i<n;i++)
#define rrep(i, n, m) for(int i=n;i>=m;i--)
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    int N, M;
    cin >> N >> M;
    Graph G(N, vector<int>());
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
    }
    int s, t;
    cin >> s >> t;
    s--;
    t--;

    vector<vector<int>> dist;
    dist.assign(N, vector<int>(3, -1));
    dist[s][0] = 0;
    queue<P> queue;
    queue.push({s, 0});
    while (!queue.empty()) {
        P p = queue.front();
        queue.pop();
        int target = p.first;
        int cost = p.second;
        for (auto v : G[target]) {
            int tmp = (cost + 1) % 3;
            if (dist[v][tmp] == -1) {
                dist[v][tmp] = dist[target][cost] + 1;
                queue.push({v, tmp});
            }
        }
    }
    if (dist[t][0] == -1) {
        cout << -1 << endl;
    } else {
        cout << dist[t][0] / 3 << endl;
    }

}

