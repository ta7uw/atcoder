#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;i++)
#define rep2(i, m, n) for(int i=m;i<n;i++)
#define rrep(i, n, m) for(int i=n;i>=m;i--)
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll MOD = 1000000007;
#ifdef __DEBUG

#include "cpp-pyprint/pyprint.h"

#endif

void Main() {
    int N;
    cin >> N;
    vector<int> A;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    for (int i = N; i >= 1; --i) {
        int a = A[i-1];
        int j = i;
        int tmp = 0;
        while (j <= N){
            tmp += A[j-1];
            j += i;
        }

        if (tmp % 2 == 0){
            if (a == 0) {
                continue;
            }else{
                A[i-1] = 0;
            }
        }else{
            if (a == 0) {
                A[i-1] = 1;
            }else{
                continue;
            }
        }
    }

    ll M = 0;
    for (int k = 0; k < N; ++k) {
        M += A[k];
    }

    cout << M<< endl;

    for (int l = 0; l < N; ++l) {
        if (A[l] != 0) {
            cout << l+1 << endl;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
