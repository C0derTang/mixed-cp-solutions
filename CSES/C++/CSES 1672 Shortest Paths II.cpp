#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> dist(n, vector<ll>(n, 500000000001));
    for(int i=0; i<n; ++i) dist[i][i]=0;
    for(int i=0; i<m; ++i){
        ll a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        dist[a][b] = min(dist[a][b],c);
        dist[b][a] = min(dist[b][a],c);
    }

    for(int k=0; k<n; ++k){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                dist[i][j] = min(dist[i][j], dist[k][j] + dist[i][k]);
            }
        }
    }

    while(q--){
        int a, b;
        cin >> a >> b;
        --a; --b;
        cout << (dist[a][b] == 500000000001 ? -1 : dist[a][b]) << '\n';
    }
}
