#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define FL(i, a, b) for(int i=a; i<b; ++i)
#define PB push_back
#define F first
#define S second

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<vi> lmao(n);
	FL(i, 0, n) {
		vi row(n, 0);
		cin >> row[i];
		lmao[i] = row;
	}


	for(int i=n-1; i>-1; --i){
		int rem = lmao[i][i];
		stack<pii> st;
		st.push({i, i});
		while (!st.empty()){
			pii cur = st.top();
			st.pop();
			lmao[cur.F][cur.S] = lmao[i][i];
			--rem;
			if (rem <= 0) break;
			
			if (cur.S-1 >= 0 && lmao[cur.F][cur.S-1] == 0) st.push({cur.F, cur.S-1});
			if (cur.F+1 < n && lmao[cur.F+1][cur.S] == 0) st.push({cur.F+1, cur.S});
		}
	}
	FL(i, 0, n){
		FL(j, 0, i+1)cout << lmao[i][j] << ' ';
		cout << '\n';

	}


	
}
