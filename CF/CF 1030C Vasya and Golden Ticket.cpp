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
	cin >> n;
	string s;
	cin >> s;
	int a[n];
	for (int i=0; i<n; ++i) {
		a[i] = s[i] - '0';
	}
	int sum = 0;
	for (int i=0; i<n-1; ++i) {
		sum += a[i];
		int othersum = 0;
		bool shit = false;
		bool didsmth = false;
		for (int j=i+1; j<n; ++j) {
			othersum += a[j];
			if (othersum > sum){
				shit = true;
				break;
			}else if (othersum == sum){
				othersum = 0;
				didsmth = true;
			}
		}
		if (!shit && othersum == 0 && didsmth) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	
}
