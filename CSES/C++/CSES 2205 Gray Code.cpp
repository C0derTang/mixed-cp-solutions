#include <bits/stdc++.h>
using namespace std;
 
vector<string> generate(int n){
	if (n==1){
		return {"0", "1"};
	}
	vector<string> prev = generate(n-1);
	vector<string> frontnew;
	for (auto x: prev) {
		frontnew.push_back('0'+x);
	}
	vector<string> backnew;
	for (auto x: prev) {
		backnew.push_back('1'+x);
	}
	reverse(backnew.begin(), backnew.end());
 
	frontnew.insert(frontnew.end(), backnew.begin(), backnew.end());
	return frontnew;
}
 
int main() {
	int n;
	cin >> n;
 
	vector<string> ans = generate(n);
	for (auto x: ans){
		cout << x << '\n';
	}
}
