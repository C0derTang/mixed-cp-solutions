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

bool isprime(int num){
    for(int i=2; i*i <= num; ++i) if(num%i == 0) return false;
    return true;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    if(a[0] == 1){
        cout << "Yes\n";
        return;
    }
    int f = a[0], s=a[1];
    for (int i=1; i<n; ++i){
        if (a[i]%f != 0){
            s = a[i];
            break;
        }
    }

    bool val=true;
    for(auto x: a){
        if(x%f != 0 && x%s != 0){
            val = false;
            break;
        }
    }
    cout << (val ? "Yes" : "No") << '\n';
    
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