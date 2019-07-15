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
    int N, M;
    cin >> N >> M;
    Graph query(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        query[a-1].push_back(b-1);
    }
    vector<unordered_map<int, int>> graph(N, unordered_map<int, int>());
    for (int i = 1; i < N; ++i) {
        graph[i][0] = 0;
        graph[0][i] = 0;
    }
    for (int j = 0; j < N; ++j) {
        int a = j;
        for (int i = 0; i < query[j].size(); ++i) {
            int b = query[j][i];
            //print(query[i]);
            if (a != 0 && b != 0) {
                graph[a][0] += 1;
                graph[0][a] += 1;
                graph[0][b] += 1;
                graph[b][0] += 1;
            } else if(a == 0) {
                graph[0][b] += 1;
                graph[b][0] += 1;
            }else{
                graph[0][a] += 1;
                graph[a][0] += 1;
            }
        }
    }
//    for (int k = 0; k < N; ++k) {
//        for (int i = 0; i < graph[k].size(); ++i) {
//            cout << k << ": "<< i <<" => " << graph[k][i] << endl;
//        }
//    }
    bool flg = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < graph[i].size(); ++j) {
            int tmp = graph[i][j];
            if (tmp % 2 == 0) {
                continue;
            }else{
                flg = false;
            }
        }
    }
    if(flg) {
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
