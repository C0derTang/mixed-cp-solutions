#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ll long long


void solve(){
	int n;
	cin >> n;
	map<int, int> a;
    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        ++a[x];
    }

    set<int> c;
    bool cutoff = false;
    for (auto e : a) {
        if (e.second > 1){
            c.insert(e.first);
        }
        else{
            if (cutoff){
                break;
            }else{
                cutoff = true;
                c.insert(e.first);
            }
        }
    }
    for (int i=0; i<n+1; ++i) {
        if (c.find(i) == c.end()){
            cout << i << '\n';
            return;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
}
