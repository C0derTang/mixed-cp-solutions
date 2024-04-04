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
	string s; cin >> s;
	stack<char> st;

	map<int, int> closest;
	int ans = 0;
	FL(i, 0, s.size()){
		if (closest.find(s[i]) == closest.end()){
			closest[s[i]] = i;
		}else{
			if (i - closest[s[i]] == 1){
				ans += closest.size()-1;
			}else{
				ans += i-closest[s[i]]-1;
				ans += (closest.size()-(i-closest[s[i]]));
			}
			closest.clear();
		}
	}
	ans += closest.size();
	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
}
