#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
    ll n,m, L;
    cin >> n >> m >> L;
    vector<pair<ll, ll>> path(n+m);
    for(int i=0; i<n; ++i){
        ll s; cin >> path[i].first >> s;
        path[i].second = path[i].first-s-1;
    }
    for(int i=n; i<n+m; ++i) cin >> path[i].first >> path[i].second;
    sort(path.begin(), path.end());
    //for(auto x: path) cout << x.first << ' ' << x.second << '\n';

    ll ans=0;
    ll power = 1;
    priority_queue<ll> pq;
    for(auto x:path){
        if (x.second >=0){ pq.push(x.second);}
        else{
            while(!pq.empty() && power <= -x.second){
                power += pq.top();
                pq.pop();
                ++ans;
            }
            if (power <= -x.second){
                cout << "-1\n";
                return;
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
