#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int mark=-1;
    for(int i=0; i<n; ++i){
        cin >> a[i];
        if (abs(a[i]) != 1) mark = i;
    }
    
    int max1=0, min1=0;
    int curmax=0, curmin=0;
    for(int i=0; i<(mark != -1 ? mark : n); ++i){
        curmax = max(a[i], curmax+a[i]);
        max1 = max(max1, curmax);
        curmin = min(a[i], curmin+a[i]);
        min1 = min(min1, curmin);
    }
    int max2 = 0, min2 = 0;
    curmax = curmin = 0;
    for(int i=(mark != -1 ? mark+1 : n); i<n; ++i){
        curmax = max(a[i], curmax+a[i]);
        max2 = max(max2, curmax);
        curmin = min(a[i], curmin+a[i]);
        min2 = min(min2, curmin);
    }
    
    set<int> ans;
    for(int i=min1; i<=max1; ++i){
        ans.insert(i);
    }
    for(int i=min2; i<=max2; ++i){
        ans.insert(i);
    }
    if (mark != -1){
        int lmin = 0, lmax= 0;
        int curl = 0;
        int l = mark-1;
        while(l >= 0){
            curl += a[l];
            lmin = min(lmin, curl);
            lmax = max(lmax, curl);
            --l;
        }
        int rmin = 0, rmax= 0;
        int curr = 0;
        int r = mark+1;
        while(r < n){
            curr += a[r];
            rmin = min(rmin, curr);
            rmax = max(rmax, curr);
            ++r;
        }
        for(int i=min(lmin+rmin, min(lmin, rmin)); i<=max(lmax+rmax, max(lmax, rmax)); ++i) ans.insert(a[mark]+i);

    }
    ans.insert(0);
    if (mark != -1) ans.insert(a[mark]);
    cout << ans.size() << '\n';
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