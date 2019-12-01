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
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W, K;
    cin >> H >> W >> K;
    vector<string> A;
    int diff = 1000000;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    P start;
    for (int i = 0; i < H; ++i) {
        string s;
        cin >> s;
        A.push_back(s);
        for (int j = 0; j < W; ++j) {
            if (s[j] == 'S') {
                start = {i, j};
                diff = min(min(i, H - 1 - i), min(j, W - 1 - j));
                visited[i][j] = true;
            }
        }
    }
    deque<P> queue;
    queue.push_back(start);

    while (!queue.empty()) {
        P q = queue.front();
        queue.pop_front();
        for (int i = 0; i < 4; ++i) {
            int x = dx[i];
            int y = dy[i];
            int a = q.first;
            int b = q.second;
            if (abs(a - start.first) + abs(b - start.second) > K) {
                continue;
            }
            int tmp = min(min(a, H - 1 - a), min(b, W - 1 - b));
            if (tmp < diff){
                diff = tmp;
            }
            if ((0 <= a + y && a + y <= H - 1) && 0 <= b + x && b + x <= W - 1) {
                if (visited[a + y][b + x] || A[a + y][b + x] != '.') {
                    continue;
                } else {
                    queue.push_back({a + y, b + x});
                    visited[a + y][b + x] = true;
                }
            }
        }
    }
    int ans = 1;
    if (diff == 0) {
        cout << ans << endl;
    } else {
        cout << ans + ((K - 1) + diff) / K << endl;
    }


}
