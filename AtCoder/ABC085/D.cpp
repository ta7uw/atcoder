#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll, ll>;
using edge = pair<ll, P>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
using Graph = vector <vector<ll>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
#ifdef __DEBUG

#include "cpp-pyprint/pyprint.h"

#endif

void Main() {
    int N, H;
    cin >> N >> H;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];
    sort(A.begin(), A.end(), greater<>());
    sort(B.begin(), B.end(), greater<>());
    int max_a = A[0];
    int ans = 0;
    rep(i, N) {
        int b = B[i];
        if (b >= max_a) {
            ans++;
            H -= b;
            if (H <= 0) {
                cout << ans << endl;
                return;
            }
        }
    }
    cout << ans + (H + max_a - 1) / max_a << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
