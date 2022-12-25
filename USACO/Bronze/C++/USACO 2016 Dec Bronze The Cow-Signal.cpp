#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("cowsignal.in");
	ofstream fout("cowsignal.out");

	int m, n, k;
	fin >> m >> n >> k;

	vector<string> sig(m);
	for (int i = 0; i < m; i++) {
		fin >> sig[i];
		for (int x = 0; x < k; x++) {
			for (int j = 0; j < n; j++) {
				for (int x2 = 0; x2 < k; x2++) {
					fout << sig[i][j];
				}
			}
			fout << '\n';
		}
		
	}



}
