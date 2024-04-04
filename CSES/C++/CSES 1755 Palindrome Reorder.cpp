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
	vi count(26);
	for (auto c: s) ++count[c-'A'];

	vector<char> ans;
	int odd = -1;
	FL(i,0,26){
		if (count[i] % 2 == 1){
			if (odd != -1){
				cout << "NO SOLUTION";
				return;
			}else{
				odd = i;
				
			}
		}
		FL(j,0,count[i]/2) ans.PB(i+'A');
	}
	if (odd != -1) ans.PB(odd+'A');
	for (int i=25; i>-1; --i){
		FL(j,0,count[i]/2) ans.PB(i+'A');
		}

	for (auto c: ans) cout << c;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	while(t--){
		solve();
	}
}
