#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll, ll>;
using edge = pair<ll, P>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
using Graph = vector<vector<ll>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
#ifdef __DEBUG

#include "cpp-pyprint/pyprint.h"

#endif

vector<ll> divisor(ll N) {
    vector<ll> res;
    for (ll i = 1L; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            ll j = N / i;
            if (j != i) {
                res.push_back(j);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}

void Main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    int ans = 0;
    sort(A.begin(), A.end());
    vector<bool> used(N, false);
    rep(i, N) {
        int a = A[i];
        bool any = false;
        if (!used[i]){
            any = true;
            used[i] = true;
        }else{
            continue;
        }
        rep(j, N) {
            if (i == j) {
                continue;
            }
            if (A[j] % a == 0) {
                any = true;
                used[j] = true;
            }
        }
        if (any) {
            ans ++;
        }
        bool all = true;
        rep(j, N) {
            if (!used[j]) all = false;
        }
        if (all) {
            break;
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
