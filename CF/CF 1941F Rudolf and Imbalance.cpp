#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve(){
    int n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(n);
	set<ll> d, f;
	for(int i=0; i<n; ++i) cin >> a[i];
	for(int i=0; i<m; ++i){
		int x; cin >> x;
		d.insert(x);
	}
	for(int i=0; i<k; ++i){
		int x; cin >> x;
		f.insert(x);
	}

	ll maxgap = 0, l=0, r=0, secondgap = 0;
	for(int i=1; i<n; ++i){
		if (a[i]-a[i-1] > maxgap){
			l = a[i-1];
			r = a[i];
			secondgap = maxgap;
			maxgap = r-l;
		}else if (a[i]-a[i-1] > secondgap){
			secondgap = a[i]-a[i-1];
		}
	}
	ll ans = maxgap;
	for(auto i: d){
		auto it = f.lower_bound((r+l)/2 - i);
		ans = min(ans, max(r-(*it+i), (*it+i)-l));
		if (it != f.begin()){
			--it;
			ans = min(ans, max(r-(*it+i), (*it+i)-l));
			++it;
		}
		++it;
		if (it != f.end()) ans = min(ans, max(r-(*it+i), (*it+i)-l));
	}
	cout << max(ans, secondgap) << '\n';

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