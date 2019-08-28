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

char grid[505][505];
bool visited[505][505];

void Main() {
    int H, W;
    cin >> H >> W;
    P start;
    P goal;
    rep(i, H) {
        string s;
        cin >> s;
        rep(j, W) {
            grid[i][j] = s[j];

            if (s[j] == 's') {
                start = make_pair(i, j);
            }

            if (s[j] == 'g') {
                goal = make_pair(i, j);
            }
        }
    }

    deque<tuple<int, int, int>> que;
    que.push_back(make_tuple(start.first, start.second, 0));
    bool flag = false;
    while (que.size() >= 1) {
        auto q = que.front();
        que.pop_front();
        for (int i = 0; i < 4; ++i) {
            int x = get<1>(q) + dx[i];
            int y = get<0>(q) + dy[i];
            int v = get<2>(q);
            if (0 <= x && x < W && 0 <= y && y < H) {
                if (visited[y][x] || v >= 3) {
                    continue;
                }

                if (grid[y][x] == '.') {
                    visited[y][x] = true;
                    que.push_front(make_tuple(y, x, v));
                }
                if (grid[y][x] == '#' && v <= 1) {
                    visited[y][x] = true;
                    que.push_back(make_tuple(y, x, v + 1));
                }
                if (grid[y][x] == 'g') {
                    visited[y][x] = true;
                    flag = true;
                }
            }
        }
    }
    cout << (flag ? "YES" : "NO") << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
