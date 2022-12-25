#include <bits/stdc++.h>
using namespace std;

const int n = 3;
int c[n], m[n];

void pour(int i, int j){
	int amt = min(m[i], c[j]-m[j]);
	m[i] -= amt;
	m[j] += amt;
}

int main() {
	ifstream fin("mixmilk.in");
	ofstream fout("mixmilk.out");

	for (int i = 0; i < n; i++) {
		fin >> c[i] >> m[i];
	}

	for (int i = 0; i < 100; i++) {
		pour(i%n, (i+1)%n);
	}
	for (int i = 0; i < n; i++) {
		fout << m[i] << '\n';
	}
}
