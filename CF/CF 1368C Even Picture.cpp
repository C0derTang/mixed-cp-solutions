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
	
	cout <<(n+2) + (2*(n+1)) << '\n';
	int x = 0, y = 0;
	cout << x << ' ' << y << '\n';
	cout << x << ' ' << y+1 << '\n';
	++x; ++y;
	while (n--){
		cout << x << ' ' << y << '\n';
		cout << x << ' ' << y+1 << '\n';
		cout << x << ' ' << y-1 << '\n';
		++x; ++y;
	}
	cout << x << ' ' << y << '\n';
	cout  << x << ' ' << y-1 << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
	while(t--){
		solve();
	}
}
