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
    int N, K;
    cin >> N >> K;
    vector<int> t(N);

    for (int i = 0; i < N; ++i) {
        cin >> t[i];
    }

    int ans = 0;
    int cnt = 0;
    int day = 0;
    for (int i = 2; i < N; ++i) {
        int a = t[i];
        int b = t[i - 1];
        int c = t[i - 2];
        cnt = a + b + c;
        if (cnt < K) {
            ans = i + 1;
            cout << ans << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
