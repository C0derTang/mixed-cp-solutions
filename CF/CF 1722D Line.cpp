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
    string s; cin >> s;
    vector<int> count(n);
    int ans=0;
    for(int i=0; i<n; ++i){
        if(s[i] == 'L'){
            count[i] = i-(n-i-1);
            ans += i;
        }else{
            count[i] = (n-i-1)-i;
            ans += n-i-1;
        }
    }
    sort(count.begin(), count.end());
    for(int i=0; i<n; ++i){
        ans = max(ans, ans+-(count[i]));
        cout << ans << ' ';
    }
    cout << '\n';
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