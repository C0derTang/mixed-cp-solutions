#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
    int k; cin >> k;
    vector<int> a(k);
    for(int i=0; i<k; ++i) cin >> a[i];
   set<int> comp;
    for(auto x: a){
        if ((k-2)%x) continue;
        if(comp.count(x)){
            cout << (k-2)/x << ' ' << x <<'\n';
            return;
        }
        comp.insert((k-2)/x);
    }
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
