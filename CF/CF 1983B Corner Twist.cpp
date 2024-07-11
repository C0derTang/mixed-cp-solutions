#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>

#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define F0R(i, a) for(int i=0; i<a; ++i)
#define ROF(i, a, b) for(int i=b; i>a-1; --i)
#define R0F(i, a) for(int i=a; i>-1; --i)

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(n);
    F0R(i, n) cin >> a[i];
    F0R(i, n) cin >> b[i];

    vector<vi> c(n, vi(m));
    F0R(i, n){
        F0R(j, m){
            c[i][j] = b[i][j] - a[i][j] < 0 ? b[i][j] + 3 - a[i][j] : b[i][j] - a[i][j];
        }
    }

    F0R(i, n-1){
        F0R(j, m-1){
            if (c[i][j] == 2){
                c[i][j] = 0;
                c[i+1][j+1] = (c[i+1][j+1]+1)%3;
                c[i+1][j] = (c[i+1][j]+2)%3;
                c[i][j+1] = (c[i][j+1]+2)%3;
            }
            else if (c[i][j] == 1){
                c[i][j] = 0;
                c[i+1][j+1] = (c[i+1][j+1]+2)%3;
                c[i+1][j] = (c[i+1][j]+1)%3;
                c[i][j+1] = (c[i][j+1]+1)%3;
            }
        }
    }
    F0R(i, n){
        F0R(j, m){
            if (c[i][j] != 0){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";

    
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
