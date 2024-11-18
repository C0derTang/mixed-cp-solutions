#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> enem(n);
    for(int i=0; i<n; ++i) cin >> enem[i].second;
    for(int i=0; i<n; ++i) cin >> enem[i].first;
    sort(enem.begin(), enem.end());

    int l=1, r=1000000001;
    bool val = true;
    while(l<r){
        int mid = (l+r)/2;

        val = true;
        vector<pair<ll, int>> smashes;
        for(int i=0; i<n; ++i){
            ll minm = (enem[i].second + mid-1)/mid;
            if(minm> m) continue;
            smashes.push_back({enem[i].first-(m-minm), 1});
            smashes.push_back({enem[i].first + (m-minm) + 1, -1});
        }
        if (smashes.empty()) val = false;
        sort(smashes.begin(), smashes.end());
        ll curcount = 0, maxcount = 0;
        for(auto x: smashes){
            curcount += x.second;
            if (curcount > maxcount) maxcount = curcount;
        }
        val = (maxcount >= k);

        if(val) r = mid;
        else l = mid+1;
    }
    cout << (l==1000000001 ? -1 : l) << '\n';
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
