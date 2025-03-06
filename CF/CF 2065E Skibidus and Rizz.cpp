#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    if (max(m, n) < k || abs(m-n) > k){
        cout << "-1\n";
        return;
    }
    vector<int> ans;
    int val = (m>n ? 1 : 0);
    for(int i=0; i<k; ++i) ans.push_back(val);

    if (val) m-=k;
    else n-=k;

    while(n>0 && m>0){
        val ^= 1;
        ans.push_back(val);
        if (val) --m;
        else --n;
    }
    if(max(m, n) > k){ 
        cout << "-1\n";
        return;
    }
    for(auto x: ans) cout << x;
    if(m>n) while(m--) cout << '1';
    else while(n--) cout << '0';
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