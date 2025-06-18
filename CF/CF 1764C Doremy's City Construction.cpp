#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

const int dulo = 998244353;



bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}


void solve(){
    int n; cin >> n;
    map<int, int> count;
    for(int i=0; i<n; ++i){
        int x; cin >> x;
        ++count[-x];
    }
    if(count.size() ==1){
        cout << count.begin()->second/2 << '\n';
        return;
    }

    int ans=0, curans=0;
    int past = 0;

    auto p1 = count.begin();
    auto p2 = p1;
    ++p2;
    ans = curans = p1->second * (n-p1->second);
    past += p1->second;
    while(p2 != count.end()){
        curans += p2->second *(n-past-p2->second);
        curans -= p2->second*past;
        past += p2->second;
        ++p1;
        ++p2;
        ans = max(ans, curans);
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