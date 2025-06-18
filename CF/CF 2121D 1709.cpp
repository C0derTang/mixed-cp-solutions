#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

const int dulo = 998244353;

ll binexp(ll a, ll b){
    ll ret = 1;
    while (b>0){
        if (b&1) ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}

ll modinv(ll a){
    return binexp(a, dulo-2);
}

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}


void solve(){
    //this is parity count right
    int n; cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    map<int, pair<int, int>> pos;
    for(int i=0; i<n; ++i){
        cin >> a[0][i];
        pos[a[0][i]] = {0,i};
    }
    for(int i=0; i<n; ++i){
        cin >> a[1][i];
        pos[a[1][i]] = {1,i};
    }

    vector<pair<int, int>> ans;
    for(int i=1; i<2*n+1; ++i){
        if(pos[i].first != (i+1)%2){
            ans.push_back({3, pos[i].second+1});
            pos[i].first ^= 1;
            pos[a[pos[i].first][pos[i].second]].first ^=1;
            swap(a[0][pos[i].second], a[1][pos[i].second]);
        }
        while(pos[i].second != (i-1)/2){
            if(pos[i].second > (i-1)/2){
                ans.push_back({pos[i].first+1, pos[i].second});
                ++pos[a[pos[i].first][pos[i].second-1]].second;
                --pos[i].second;
                swap(a[pos[i].first][pos[i].second], a[pos[i].first][pos[i].second+1]);
            }else{
                ans.push_back({pos[i].first+1, pos[i].second+1});
                --pos[a[pos[i].first][pos[i].second+1]].second;
                ++pos[i].second;
                swap(a[pos[i].first][pos[i].second], a[pos[i].first][pos[i].second-1]);

            }
        }
    }

    cout << ans.size() << '\n';
    for(auto x: ans) cout << x.first << ' ' << x.second << '\n';
    //cout << '\n';
}

signed main() {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin.tie(NULL) -> sync_with_stdio(false);
    
    int t; cin >> t;
    while(t--){
        solve();
    }
}