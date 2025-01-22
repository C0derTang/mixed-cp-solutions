#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<vector<int>, int>> cow(n);
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            int x; cin >> x;
            cow[i].first.push_back(x);
        }
        cow[i].second = i+1;
        sort(cow[i].first.begin(), cow[i].first.end());
    }
    sort(cow.begin(), cow.end());
    vector<int> ans;
    
    for(int i=0; i<n; ++i){
        int cur = i;
        for(int j=0; j<m; ++j){
            if (cow[i].first[j] != cur){
                cout << "-1\n";
                return;
            }
            cur += n;
        }
        ans.push_back(cow[i].second);
    }
    for(auto x: ans) cout << x << ' ';
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
