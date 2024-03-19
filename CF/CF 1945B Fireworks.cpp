#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ll long long

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

//cycle is lcm
// fire from a = lcm/a
// fire from b = lcm / b

void solve(){
	ll a, b, m;
	cin >> a >> b >> m;
	ll ans = m/a+m/b+2;
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
}
