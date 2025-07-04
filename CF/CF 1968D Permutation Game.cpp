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
    int n, k, b, s;
    cin >> n >> k >> b >> s;
    --b; --s;
    vector<int> p(n), a(n);
    for(int i=0; i<n; ++i) cin >> p[i];
    for(int i=0; i<n; ++i) cin >> a[i];
    // we can calculate in O(1) the score of each position and bf this
    // if this was dp i'd be so cooked
    // cheese time lmao
    vector<int> bscore;
    int stay1 = 0;
    for(int i=0; i<min(n, k); ++i){
        bscore.push_back(stay1 + (k-i)*a[b]);
        stay1 += a[b];
        b = p[b]-1;
    }

    vector<int> sscore;
    stay1 = 0;
    for(int i=0; i<min(n, k); ++i){
        sscore.push_back(stay1 + (k-i)*a[s]);
        stay1 += a[s];
        s = p[s]-1;
    }
    /*
    for(auto x: bscore) cout << x << ' ';
    cout << '\n';
    for(auto x: sscore) cout << x << ' ';
    cout << '\n';
*/

    int bmax = *max_element(bscore.begin(), bscore.end());
    int smax = *max_element(sscore.begin(), sscore.end());
    if(bmax > smax) cout << "Bodya\n";
    else if (smax > bmax) cout << "Sasha\n";
    else cout << "Draw\n";
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
