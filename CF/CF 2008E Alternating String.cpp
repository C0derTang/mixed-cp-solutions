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
    int n; cin >> n;
    string s; cin >> s;
    // what if we brute force the removal
    // can we calculate required changes afterward in O(1)?
    // if we know how many of each characters are in evens an odds
    // prefix evens/odds to calculate is 26*n precomp
    //max evens and max odds, compensating for shifts
    vector<vector<int>> evens(26, vector<int>(n+1)), odds(26, vector<int>(n+1));
    for(int i=0; i<n; ++i){
        for(int j=0; j<26; ++j) evens[j][i+1] = evens[j][i];
        for(int j=0; j<26; ++j) odds[j][i+1] = odds[j][i];
        if(i%2) ++odds[s[i]-'a'][i+1];
        else ++evens[s[i]-'a'][i+1];
    }
    if(n%2==0){
        int maxe=0, maxo=0;
        for(int i=0; i<26; ++i){
            maxe = max(maxe, evens[i][n]);
            maxo = max(maxo, odds[i][n]);
        }
        cout << n-maxe-maxo << '\n';
        return;
    }
    int ans=n;
    for(int i=1; i<n+1; ++i){
        int maxe=0, maxo=0;
        for(int j=0; j<26; ++j){
            maxe = max(maxe, evens[j][i-1]+odds[j][n]-odds[j][i]);
            maxo = max(maxo, odds[j][i-1]+evens[j][n]-evens[j][i]);
        }
        ans = min(ans, n-maxe-maxo);
    }
    cout << ans << '\n';
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