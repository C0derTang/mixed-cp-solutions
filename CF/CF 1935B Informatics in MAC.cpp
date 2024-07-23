#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <vector>

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
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

void solve(){
	//a sequence is only invalid if there is ONE of it in existence at a time
	// ^ thats false i lied counterexample: 0 1 0 1 2 3 2 3
	// is it an intervals problem
	

	//ok random assumption no 369
	// you can split all valid ones into 2 parts only
	// proof because i said so
	// and its only valid if 0 overlaps with 1 overlaps with 2 overlaps with 3 etc etc etc?
	// wait then where do we split the array
	//maybe not intervals

	//"you can split all valid ones into 2 parts only" is true tho
	// is "prefix mex" possible

	//oh wait what if we bsearch on the mex
	//and just brute force the smallest possible segment that has that same mex.
	//but what would be the bsearch condition? if it final mex is over or under ig

	// O(n^2) would just be brute forcing at every position and calculating the mex before and after that position
	// that should work

	//wait wait wait
	// prefix mex and suffix mex
	// multiset bash trust
	//nlogn
	// im actually dogshit at this wtf
	// pain implement
	// nooo blue lock egoooo
	// tweaking

	int n; cin >> n;
	vi a(n);
	multiset<int> suff;
	set<int> pref;
	int prefmex=0; int suffmex=0;
	F0R(i, n){
		cin >> a[i];
		suff.insert(a[i]);
	}

	while(suff.find(suffmex) != suff.end()) ++suffmex;
	//multiset abuse

	F0R(i, n){
		pref.insert(a[i]);
		while(pref.count(prefmex)) ++prefmex;
		// WAIT WAIT WAIT
		// WE CAN SET ABUSE SO HARD
		// WE CAN CHECK IF THE RIGHTMOST ELEMENT OF THE SET == THE LENGTH OF THE SET-1
		// SINCE SETS CANT HAVE DUPLICATES
		// AHAHAHAHAHAHA I LOVE THIS DATA STRUCTURE
		// wait
		// fuck
		// no we can literally go thru the set backwards until we find one that works
		// still shitty O(n) in worst case tho
		//hmmm 
		//hopeforces
		// nah wait we can combine the previous methods and stuff
		//surely
		// wait im legit trippin balls i think
		suff.erase(suff.find(a[i]));
		if (suff.find(a[i]) == suff.end()) suffmex = min(a[i], suffmex);
		if(suffmex == prefmex){
			cout << "2\n" << 1 << ' ' << i+1 << '\n' << i+2 << ' ' << n << '\n';
			return;
		}
	}
	cout << "-1\n";
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
