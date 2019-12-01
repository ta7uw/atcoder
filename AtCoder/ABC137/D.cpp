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

void Main() {
    int N, M;
    cin >> N >> M;
    unordered_map<int, vector<int>> dic;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        dic[a].push_back(b);
    }

    ll ans = 0;
    priority_queue<int> queue;
    for (int i = 1; i <= M; ++i) {
        if (dic[i].size() != 0) {
            for (int j = 0; j < dic[i].size(); ++j) {
                int tar = dic[i][j];
                queue.push(tar);
            }
        }
        if (queue.size() >= 1) {
            int tmp = queue.top();
            ans += tmp;
            queue.pop();
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
