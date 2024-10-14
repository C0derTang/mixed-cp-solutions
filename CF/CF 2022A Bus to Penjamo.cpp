#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
    int n, r;
	cin >> n >> r;
	vector<int> a(n);

    int sum = 0;
	for(int i=0; i<n; ++i){
        cin >> a[i];
        sum += a[i];
    }
    int res = (2*r-sum);
    int ans=0;
    for(auto x: a){
        ans += (x/2)*2;
        if (res > 0 && x%2==1){
            ++ans; --res;
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
