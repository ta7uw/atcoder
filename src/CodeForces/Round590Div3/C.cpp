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
 * C. Pipes
 * https://codeforces.com/contest/1234/problem/C
 *
 *　シミュレーションを行う。dfsで実装したが通るべきルートは一意に定まるので
 * ループを回すだけでよい
 */

bool dfs(int i, int j, bool right, vector<vector<int>> &grid, int N) {
    if (i == 1 && j == N - 1) {
        if (grid[j][i] > 2 && !right) {
            return true;
        }
        if (grid[j][i] <= 2 && right) {
            return true;
        }
        return false;
    }
    if (j >= N) {
        return false;
    }
    bool res = false;
    if (right) {
        if (grid[j][i] <= 2) {
            res |= dfs(i, j + 1, right, grid, N);
        } else {
            res |= dfs(1-i, j, !right, grid, N);
        }
    } else {
        if (grid[j][i] <= 2) {
            return false;
        }else{
            res |= dfs(i, j + 1, !right, grid, N);
        }
    }
    return res;
}

void Main() {
    int Q;
    cin >> Q;
    rep(q, Q) {
        int N;
        cin >> N;
        string s1, s2;
        cin >> s1 >> s2;
        vector<vector<int>> grid(N, vector<int>());
        rep(i, N) {
            vector<int> tmp;
            tmp.push_back(s1[i] - '0');
            tmp.push_back(s2[i] - '0');
            grid[i] = tmp;
        }
        if (dfs(0, 0, true, grid, N)) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
