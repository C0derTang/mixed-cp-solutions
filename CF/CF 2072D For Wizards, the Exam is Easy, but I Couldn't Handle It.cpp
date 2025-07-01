#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

const int dulo = 998244353;

int binexp(int a, int b){
    int ret = 1;
    while (b>0){
        if (b&1) ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}

int modinv(int a){
    return binexp(a, dulo-2);
}

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}


void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];

    vector<vector<int>> count(n);
    for(int i=0; i<n; ++i){
        count[i].push_back(0);
        for(int j=i+1; j<n; ++j){
            count[i].push_back(count[i].back());
            count[i][count[i].size()-1] += (a[j] < a[i]) - (a[j] > a[i]);
        }
    }

    int maxc=-1;
    int l=0, r=0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<count[i].size(); ++j){
            if (count[i][j] > maxc){
                maxc = count[i][j];
                l=i+1;
                r=i+1+j;
            }
        }
    }
    cout << l << ' ' << r << '\n';
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