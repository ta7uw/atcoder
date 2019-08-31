#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
typedef long long ll;
#define rep(i, n) for(int i=0;i<(n);i++)
#define rep2(i, m, n) for(int i=m;i<(n);i++)
#define rrep(i, n, m) for(int i=n;i>=(m);i--)
using Graph = vector <vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1000000000000000000L;
#ifdef __DEBUG

#include "cpp-pyprint/pyprint.h"

#endif

void Main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    unordered_map<int, vector<int>> target;
    rep(i, N) {
        int a = A[i];
        int cnt = 0;
        while (a != 0) {
            target[a].push_back(cnt);
            a /= 2;
            cnt++;
        }
        target[a].push_back(cnt);
    }
    int ans = INF;
    for (auto &p: target) {
        if (p.second.size() >= K) {
            sort(p.second.begin(), p.second.end());
            ans = min(ans, accumulate(p.second.begin(), p.second.end() - (p.second.size() - K), 0));
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

