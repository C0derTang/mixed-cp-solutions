#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long curSum = -pow(10,9)-1;
	long long totSum = -pow(10,9)-1;
	for (int i=0; i<n; ++i) {
		long long num;
		cin >> num;
		curSum = max(curSum+num, num);
		totSum = max(curSum, totSum);
	}
	cout << totSum;
}
