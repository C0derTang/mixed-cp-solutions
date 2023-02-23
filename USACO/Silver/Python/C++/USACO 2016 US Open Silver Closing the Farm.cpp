#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<vector<int>> paths(3000);
vector<int> visited(3000);
vector<int> closed(3000);
int cnt = 0;

void dfs(int cur){
	if (visited[cur] || closed[cur]) return;
	
	cnt++;
	visited[cur] = true;
	for (int p : paths[cur]) {
		if (!visited[p]) dfs(p);
	}
}

int main(){
	ifstream fin("closing.in");
	ofstream fout("closing.out");

	fin >> n >> m;

	for (int i = 0; i < m; i++) {
		int c1, c2;
		fin >> c1 >> c2;
		paths[c1].push_back(c2);
		paths[c2].push_back(c1);
	}

	vector<int> ord(n);
	for (int i = 0; i < n; i++){
		fin >> ord[i];
	}
	
	dfs(1);

	if (cnt == n){
		fout << "YES\n";
	}else{
		fout << "NO\n";
	}

	for (int i = 0; i < n-1; i++) {
		cnt = 0;
		closed[ord[i]] = true;
		fill(visited.begin(), visited.end(), false);
		dfs(ord[n-1]);

		if (cnt == n - i -1){
			fout << "YES\n";
		}else{
			fout << "NO\n";
		}
	}

}
