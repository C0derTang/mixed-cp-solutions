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



signed main() {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin.tie(NULL) -> sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }

    //oh shit construction
    set<int> mex;
    set<int> nottaken;
    for(int i=0; i<n; ++i) nottaken.insert(i);
    vector<int> b(n);
    for(int i=0; i<n; ++i){
        if (a[i] == 0 || (mex.lower_bound(a[i]) == mex.end() && mex.size() == a[i])){
            b[i] = 1000000;
            continue;
        }
        
        int stop = 0;
        if (!mex.empty()) stop = (*mex.rbegin())+1;
        int start = a[i]-1;
        auto it = nottaken.upper_bound(i);
        --it;
        while(stop <= start){
            int cur = *it;
            b[*it] = stop;
            mex.insert(stop);
            ++stop;
            --it;
            nottaken.erase(cur);
        }
    }
    for(auto x: b) cout << x << ' ';
    cout << '\n';
}