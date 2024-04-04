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
	int n;
	cin >> n;
	int ans=1;
	FL(i,0,n){
		ans *= 2;
		ans %= MOD;
	}
	cout << ans;
}
 
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	while(t--){
		solve();
	}
}