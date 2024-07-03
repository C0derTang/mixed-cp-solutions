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
	int n; cin >> n;
	if (n<=3 && n != 1) {
		cout << "NO SOLUTION";
		return;
	}

	for (int i=2; i<n+1; i += 2) {
		cout << i << ' ';
	}
	for (int i=1; i<n+1; i += 2) {
		cout << i << ' ';
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
