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
	string s;
	cin >> s;
	char cur = s[0];
	int cursum = 0, maxsum = 0;
	FL(i, 0, s.size()){
		if (s[i] == cur){
			++cursum;
			maxsum = max(maxsum, cursum);
		}else{
			cursum = 1;
			cur = s[i];
		}
	}
	cout << maxsum;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	while(t--){
		solve();
	}
}
