#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 998244353;


void solve() {
    int l, r;
    cin >> l >> r;
    
    int maxlen = 0;
    int temp = 1;
    while (l*temp <= r) {
        temp *= 2;
        ++maxlen;
    }

    if (maxlen==1){
        cout << maxlen << ' ' << r-l+1 << '\n';
        return;
    }

    int ans=0;
    
    
    int nl=l, nr=r;
    while(nl < nr){
        int mid=(nl+nr)/2;
        if (mid*temp/2 > r) nr=mid;
        else nl = mid+1;
    }
    ans += nl - l;

    nl=l; nr=r;
    while(nl < nr){
        int mid=(nl+nr)/2;
        if (mid*temp/4*3 > r) nr=mid;
        else nl = mid+1;
    }
    ans += (maxlen-1) * (nl-l);
    

    cout << maxlen << ' ' << ans << '\n';
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
