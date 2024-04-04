#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define FL(i, a, b) for(int i=a; i<b; ++i)
#define PB push_back
#define F first
#define S second
 
int MOD = 1000000007;
 
bool cbs(pii a, pii b) {
    return a.second < b.second;
}
 
void solve(){
	int x, y;
	cin >> x >> y;
 
	int big = max(x, y);
	int small = min(x,y);
	
	if ((2*big - small)%3 == 0 && (2*big - small)/3 <= small){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
 
 
}
 
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
}