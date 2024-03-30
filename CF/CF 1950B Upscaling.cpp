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
	FL(i, 0, n){
		FL(x,0,2){
			FL(j, 0, n){
				if (j%2 == 0){
					if (i%2==0) cout <<"##";
					else cout << "..";
				}
				else {
					if (i%2==0) cout <<"..";
					else cout << "##";
				}
			}
			cout << '\n';
		}
		
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
