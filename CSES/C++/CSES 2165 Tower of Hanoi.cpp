#include <bits/stdc++.h>
#include <vector>
using namespace std;

int n;
vector<int> pos(n+1);
vector<pair<int, int>> ans;

void locate(int disc, int op1, int op2){
	if (disc == 0) return;
	locate(disc-1, op2, op1);
	ans.push_back({3-op1-op2+1, op1+1});

	// put back onto the tower except idk how??
	locate(disc-1, op1, 3-op1-op2);
	

}

int main() {
	cin >> n;

	//123 0 0 n+1 observations
	//1234 0 0
	// 234 1 0
	//34 1 2
	//34 0 12
	//4 3 12
	//14 3 2
	//14 23 0
	//4 123 0
	// 0 123 4

	// to get disc n onto the bottom you need to put 1 - n-1 discs in order in the middle
	//to put disc n-1 in the middle you need to put the discs 1-n-2 on the right
	//but after you put disc n onto the bottom you need to order the other ones on top of them

	// 1,3, 1,2
	locate(n, 2, 1);
	cout << ans.size() << '\n';
	for (auto x : ans) {
		cout << x.first << ' ' << x.second << '\n';
	}
}
