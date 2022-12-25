#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
	ifstream fin("paint.in");
	ofstream fout("paint.out");

	int a, b, c, d;
	fin >> a >> b >> c >> d;

	vector<bool> painted(100);
	for (int i = a; i < b; i++){
		painted[i] = true;
	}
	for (int i = c; i < d; i++){
		painted[i] = true;
	}

	int ans = 0;
	for (int i = 0; i < 100; i++){
		ans += painted[i];
	}

	fout << ans << endl;
}