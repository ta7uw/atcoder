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

/**
 * https://codeforces.com/contest/1230/problem/C
 *
 * dfsで各頂点ごとにサイコロの目を固定する全探索。
 * 頂点数はNなので6^Nの探索を行い、サイコロの配分が決まれば、貪欲にサイコロの組み合わせを割り当てていく。
 * サイコロの組み合わせは toId関数を使うことでa, bの目で一意な値を返すようにする。
 * すでにつかったサイコロの組みのidのときは使えないことになる。
 */

int N, M;
Graph graph;

int toId(int a, int b) {
    if (a > b) swap(a, b);
    return a + 7 * b;
}

int dfs(int now, vector<int> &dice) {
    int tmp = 0;
    unordered_set<int> used;
    if (now == N - 1) {
        rep(i, N) {
            for (int v: graph[i]) {
                int id = toId(dice[i], dice[v]);
                if (used.find(id) == used.end()) {
                    used.insert(id);
                    tmp++;
                }
            }
        }
        return tmp;
    }
    int ans = 0;
    rep2(i, 1, 7) {
        dice[now] = i;
        ans = max(ans, dfs(now + 1, dice));
    }
    return ans;
}

void Main() {
    cin >> N >> M;
    graph.resize(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> dice(N, 1);
    cout << dfs(0, dice) << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
