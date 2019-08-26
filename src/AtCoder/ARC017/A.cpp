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

bool is_prime(ll N) {
    if (N <= 1) {
        return false;
    } else {
        for (ll i = 2; i * i <= N; ++i) {
            if (N % i == 0) {
                return false;
            }
        }
    }
    return true;
}

void Main() {
    int N;
    cin >> N;
    if(is_prime(N)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
