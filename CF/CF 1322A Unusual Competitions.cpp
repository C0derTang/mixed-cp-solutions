#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ll long long

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int n;
	string s;
	cin >> n >> s;
	
	int ans=0;
	bool neg = false;
	int sum = 0;
	for (int i=0; i<n; ++i) {
		if (s[i] == '(') {
			++sum;
		}else{
			--sum;
		}
		if (sum<0){
			neg = true;
		}
		if(neg && sum<=0){
			++ans;
		}
		if(neg && sum == 0){
			neg = false;
		}
	}
	if (sum == 0){
		cout << ans;
	}else{
		cout << -1;
	}
}
