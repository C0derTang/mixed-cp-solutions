#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
    int n; cin >> n;
    vector<int> c(n);
    map<int, set<int>> pos;
    for(int i=0; i<n; ++i){
        cin >> c[i];
        --c[i];
        pos[c[i]].insert(i);
    }
    
    vector<vector<int>> ans;
    for(auto x: pos){
        if (x.second.count(x.first)) continue;
        int target = *x.second.begin();
        for(auto y: x.second){
            if (c[y] == x.first && pos[c[y]].count(x.first)){
                target = y;
                break;
            }
        }
        ans.push_back({1, target+1, x.first+1});
        pos[c[x.first]].erase(x.first);
        pos[c[x.first]].insert(target);
        swap(c[x.first], c[target]);
        pos[x.first].erase(target);
        pos[x.first].insert(x.first);
    }

    for(auto x: pos){
        //cout << x.first << '\n';
        //for(auto y: x.second) cout << y << ' ';
        //cout << '\n';
        for(auto m: x.second){
            if (m == x.first) continue;
            ans.push_back({2, x.first+1, m+1});
        }
    }

    cout << ans.size() << '\n';
    for(auto x: ans){
        for (auto c: x) cout << c << ' ';
        cout << '\n';
    }
}

signed main() {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin.tie(NULL) -> sync_with_stdio(false);
    
    //int t; cin >> t;
    //while(t--){
        solve();
    //}
}