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

vector<ll> divisor(ll N) {
    vector<ll> res;
    for (ll i = 1L; i * i< N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            ll j = N / i;
            if (j != i)  {
                res.push_back(j);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}

void Main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    ll sum = accumulate(A.begin(), A.end(), 0LL);

    vector<ll> target = divisor(sum);
    ll ans = 0;
    for(ll d: target) {
        vector<int> mod(N, 0);
        vector<int> modd(N, 0);
        rep(i, N) mod[i] = A[i] % d;
        sort(mod.begin(), mod.end());
        rep(i, N) modd[i] = d - mod[i];

        vector<ll> sum_p(N+1, 0LL);
        vector<ll> sum_m(N+1, 0LL);
        rep(i, N) {
            sum_p[i+1] += sum_p[i] + mod[i];
            sum_m[i+1] += sum_m[i] + modd[i];
        }
        rep(i, N){
            if (sum_p[i+1] - (sum_m[N] - sum_m[i+1]) == 0 && sum_p[i+1] <= K){
                ans = max(ans, d);
            }
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
