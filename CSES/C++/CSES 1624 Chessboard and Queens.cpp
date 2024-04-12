#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ans = 0;
vector<vector<char>> board(8, vector<char>(8));
vector<int> column(8);
vector<int> diag1(16);
vector<int> diag2(16);

void generate(int y){
	if (y == 8){
		++ans;
		return;
	}
	for (int x=0; x<8; ++x) {
		if (board[y][x] == '*' || column[x] || diag1[x+y] || diag2[x-y+8-1]) continue;
		column[x] = diag1[x+y] = diag2[x-y+8-1] = 1;
		generate(y+1);
		column[x] = diag1[x+y] = diag2[x-y+8-1] = 0;
	}
}

int main() {
	for (int i=0; i<8; ++i) for (int j=0; j<8; ++j) cin >> board[i][j];

	generate(0);
	cout << ans;
}
