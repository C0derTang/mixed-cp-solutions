#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n-1);
    for(int i=0; i<n-1; ++i) cin >> a[i];
    stack<int> ans;
    ans.push(a[n-2]);
    for(int i=n-2; i>0; --i){
        if (a[i] < a[i-1]) ans.push(a[i]);
        else ans.push(a[i-1]);
    }
    cout << a[0] << ' ';
    while(!ans.empty()){
        cout << ans.top() << ' ';
        ans.pop();
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