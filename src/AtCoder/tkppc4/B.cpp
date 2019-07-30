#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
typedef long long ll;
#define rep(i, n) for(int i=0;i<(n);i++)
#define rep2(i, m, n) for(int i=m;i<(n);i++)
#define rrep(i, n, m) for(int i=n;i>=(m);i--)
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll MOD = 1000000007;
#ifdef __DEBUG

#include "cpp-pyprint/pyprint.h"

#endif
bool ans = true;
vector<bool> flag;

int dfs(const Graph &G, int pos, int pre) {
    int cnt = 0;
    for (int i : G[pos]) {
        if (i == pre) continue;
        int res = dfs(G, i, pos);
        if (res >= 1) ++cnt;
    }
    if ((pre == -1 && cnt >= 3) || (pre != -1 && cnt >= 2)) ans = false;
    return cnt != 0 ? cnt : flag[pos];
}


void Main() {
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a --;
        b --;
        G[a].push_back(b );
        G[b].push_back(a );
    }
    flag.assign(N, false);
    int s = 0;
    for (int i = 0; i < M; ++i) {
        int c;
        cin >> c;
        c--;
        flag[c] = true;
        s = c;
    }
    dfs(G, s, -1);
    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "trumpet" << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
