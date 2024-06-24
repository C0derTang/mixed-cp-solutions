#include <bits/stdc++.h>

using namespace std;

#define ll long long


bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve(){
	int n; cin >> n;
	string s;
	cin >> s;
	if(n==2){
		if (s[0] == '0') cout << s[1] << '\n';
		else cout << s << '\n';
		return;
	}
	if (n==3){
		if (s[0] == '0' || s[2] == '0') {
			cout << "0\n";
		} else {
			int num1 = (s[0] - '0') + stoi(s.substr(1, 2));
			int num2 = (s[2] - '0') + stoi(s.substr(0, 2));
			int num3 = (s[0] - '0') * stoi(s.substr(1, 2));
			int num4 = (s[2] - '0') * stoi(s.substr(0, 2));
			
			int result = min({num1, num2, num3, num4});
			cout << result << "\n";
    	}
		return;
	}

	int ans = 261;
	for(int i=0; i<n-1; ++i){
		int j=0, curans=0;
		while(j<n){
			if (j==i){
				curans += stoi(s.substr(j, 2));
				j += 2;
			}else{
				if (s[j] == '0'){
					cout << "0\n";
					return;
				}else if (s[j] != '1'){
					curans += s[j]-'0';
				}
				++j;
			}
		}
		ans = min(curans, ans);
	}

	cout << ans << '\n';

}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
