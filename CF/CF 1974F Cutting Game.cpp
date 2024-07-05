#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>

#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define F0R(i, a) for(int i=0; i<a; ++i)
#define ROF(i, a, b) for(int i=b; i>a-1; --i)
#define R0F(i, a) for(int i=a; i>-1; --i)


bool cbs(pii a, pii b) {
    return a.second < b.second;
}

// straight up impl problem:
// sort and add twice to a vertical and horizontally sorted array
// binary search on non cut off segment to add pieces
// to avoid double counting keep a set of seen elements?
// shouldn't be more than nlogn because you'll only iterate over each element at most twice during set check
// right?
// self doubt
// implement anyways
// wait we dont need bsearch we can just two pointers it dope

void solve(){
	int a, b, n, m;
	cin >> a >> b >> n >> m;
	vector<pii> xsort(n), ysort(n);
	F0R(i, n){
		int x, y; cin >> x >> y;
		xsort[i] = {x, y};
		ysort[i] = {x, y};
	}
	sort(xsort.begin(), xsort.end());
	sort(ysort.begin(), ysort.end(), cbs);

	set<pii> seen;
	int alice=0, bob=0;
	int loa=0, hia=n-1, lob=0, hib=n-1;
	int mina=1, maxa=a, minb=1, maxb=b;
	
	F0R(i, m){
		char c; int k;
		cin >> c >> k;
		int ans = 0;
		if (c=='U'){
			while(lob <= hib && ysort[lob].second < minb+k){
				if (!seen.count(ysort[lob])){
					++ans;
					seen.insert(ysort[lob]);
				}
				++lob;
			}
			minb += k;
		}else if (c=='D'){
			while(lob <= hib && ysort[hib].second > maxb-k){
				if (!seen.count(ysort[hib])){
					++ans;
					seen.insert(ysort[hib]);
				}
				--hib;
			}
			maxb -= k;
		}else if (c=='L'){
			while(loa <= hia && xsort[loa].first < mina+k){
				if (!seen.count(xsort[loa])){
					++ans;
					seen.insert(xsort[loa]);
				}
				++loa;
			}
			mina += k;
		}else{
			while(loa <= hia && xsort[hia].first > maxa-k){
				if (!seen.count(xsort[hia])){
					++ans;
					seen.insert(xsort[hia]);
				}
				--hia;
			}
			maxa -= k;
		}
		if (i%2) bob += ans;
		else alice += ans;
	}
	//cout << '\n';
	cout << alice << ' ' << bob << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}