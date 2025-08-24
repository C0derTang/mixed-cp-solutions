#include <bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

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

int MAXN = 1e7;
vector<int> primes;
void precomp(){
    vector<bool> check(MAXN+1, true);
    for(int i=2; i*i<=MAXN; ++i){
        if(check[i]){
            for(int j=i*i; j<=MAXN; j+=i) check[j] = false;
        }
    }

    for(int i=2; i<=MAXN; ++i){
        if(check[i]) primes.push_back(i);
    }
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];
    sort(a.rbegin(), a.rend());
    // check if last is nth largest prime (precomp)
    // if it is larger then remove and add to total
    // otherwise if we have sufficient points add
    // else delete
    int ans=0, tot=0;
    for(int i=0; i<n; ++i){
        if (a[i] > primes[i]){
            tot += a[i] - primes[i];
        }else{
            if (tot < primes[i]-a[i]){
                ++ans;
            }else{
                tot -= primes[i]-a[i];
            }
        }
    }

    cout << ans << '\n';
}

signed main() {
    precomp();
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin.tie(NULL) -> sync_with_stdio(false);
    
    int t; cin >> t;
    while(t--){
        solve();
    }
}