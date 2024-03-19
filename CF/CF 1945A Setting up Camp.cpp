#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ll long long

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

void solve(){
	int a, b, c;
	cin >> a >> b >> c;
	if(b%3 != 0 && b%3+c < 3){
		cout << "-1\n";
	}else{
		ll ans = (a+ceil(((double)b+(double)c)/3.0));
		cout << ans << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
}
