#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

const int dulo = 11111;
const int MOD = 1e9 + 7;

vector<ll> powers(1000001);

vector<ll> polyhash(string sr){
    vector<ll> ret(sr.size()+1);
    for(int i=0; i<sr.size(); ++i) ret[i+1] = (ret[i]+(sr[i]*powers[i]))%MOD;
    return ret;
}

signed main() {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    powers[0] = 1;
    for(int i=1; i<1000001; ++i) powers[i] = (powers[i-1]*dulo)%MOD;

    cin.tie(NULL) -> sync_with_stdio(false);
    string n, m;
    cin >> n >> m;
    vector<ll> f = polyhash(n);
    vector<ll> s = polyhash(m);
    ll ans=0;
    for (int i=m.size(); i<n.size()+1; ++i){
        if((f[i]-f[i-m.size()]+MOD)%MOD == (s.back()*powers[i-m.size()])%MOD) ++ans;
    }
    cout << ans;
}