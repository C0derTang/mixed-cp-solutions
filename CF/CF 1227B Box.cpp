#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
    int n; cin >> n;
    vector<int> q(n);
    set<int> rem;
    for(int i=0; i<n; ++i){
        cin >> q[i];
        rem.insert(i+1);
    }
    int prevmax = 0;
    vector<int> ans;
    for(auto x: q){
        if (x > prevmax){
            ans.push_back(x);
            prevmax = x;
            rem.erase(x);
        }else{
            if (*rem.begin() > prevmax){
                cout << "-1\n";
                return;
            }
            ans.push_back(*rem.begin());
            rem.erase(rem.begin());
        }
    }
    for(auto x: ans) cout << x << ' ';
    cout << '\n';
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    
    int t; cin >> t;
    while(t--){
        solve();
    }
}
