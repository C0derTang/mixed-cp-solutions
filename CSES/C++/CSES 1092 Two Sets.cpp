#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define FL(i, a, b) for(int i=a; i<b; ++i)
#define PB push_back
#define F first
#define S second
 
bool cbs(pii a, pii b) {
    return a.second < b.second;
}
 
void solve(){
	int n;
	cin >> n;
	if (n < 3){
		cout << "NO";
		return;
	}
	int target = n*(n+1)/2;
	if (target%2 == 1){
		cout << "NO";
		return;
	}
	target /= 2;
	unordered_set<int> ans;
	for (int i=n; i>0; --i){
		if (target-i >=0){
			target -= i;
			ans.insert(i);
		}
	}
	if (target != 0){
		cout << "NO";
	}else{
		cout << "YES\n" << ans.size() << '\n';
		for (auto x: ans) cout << x << ' ';
		cout << '\n' << n-ans.size() << '\n';
		FL(i, 1, n+1) if (ans.find(i) == ans.end()) cout << i << ' ';
	}
}
 
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	while(t--){
		solve();
	}
}
