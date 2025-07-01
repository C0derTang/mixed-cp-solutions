#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

const int dulo = 998244353;

int binexp(int a, int b){
    int ret = 1;
    while (b > 0){
        if (b & 1) ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}

int modinv(int a){
    return binexp(a, dulo - 2);
}

bool cbs(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    vector<pair<int,int>> ans;

    int idx_max = max_element(a.begin(), a.end()) - a.begin();
    int idx_min = min_element(a.begin(), a.end()) - a.begin();

    int pivot = (abs(a[idx_max]) >= abs(a[idx_min])) ? idx_max : idx_min;

    if(a[pivot] >= 0){
        for(int i = 0; i < n; ++i){
            if(i == pivot) continue;
            a[i] += a[pivot];
            ans.push_back({i + 1, pivot + 1});
        }
        for(int i = 1; i < n; ++i){
            a[i] += a[i - 1];
            ans.push_back({i + 1, i});
        }
    }else{
        for(int i = 0; i < n; ++i){
            if(i == pivot) continue;
            a[i] += a[pivot];
            ans.push_back({i + 1, pivot + 1});
        }
        for(int i = n - 2; i >= 0; --i){
            a[i] += a[i + 1];
            ans.push_back({i + 1, i + 2});
        }
    }

    cout << ans.size() << '\n';
    for(auto p : ans) cout << p.first << ' ' << p.second << '\n';
}

signed main(){
    cin.tie(NULL)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}