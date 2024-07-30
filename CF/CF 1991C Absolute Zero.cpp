#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>

#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define F0R(i, a) for(int i=0; i<a; ++i)
#define ROF(i, a, b) for(int i=b; i>a-1; --i)
#define R0F(i, a) for(int i=a; i>-1; --i)
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

void solve(){
	int n; cin >> n;
	set<int> a;
	int avg=0;
	bool odd=false, even=true;
	F0R(i,n){
		int x; cin >>x;
		if (!a.count(x)){
			a.insert(x);
			avg += x;
		}
	}

	vll ans(40);
	F0R(i,40){
		avg = ((*a.rbegin())+(*a.begin()))/2;
		ans[i]=avg;
		set<int> newa;
		//int newavg=0;
		for(auto x: a){
			if (!newa.count(abs(x-avg))){
				newa.insert(abs(x-avg));
				//newavg += abs(x-avg);
			}
		}
		a=newa; //avg=newavg;
	}
	
	if(a.size() != 1 || *a.begin() != 0){
		cout <<"-1\n";
		return;
	}
	cout << "40\n";
	for(auto x: ans) cout << x << ' ';
	cout << '\n';

}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}