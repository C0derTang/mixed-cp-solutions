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

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

void solve(){
	int n; cin >> n;
	vi a(n), b(n), c(n);
	F0R(i, n) cin >> a[i];
	F0R(i, n) cin >> b[i];
	F0R(i, n) cin >> c[i];

	int tot = 0;
	for(auto x: a) tot += x;
	tot += 2;
	tot /= 3;

	int asum=0, bsum=0, csum=0;
	int ar=0, br=0, cr=0;
	F0R(i, n){
		if(asum<tot){ asum += a[i]; ar=i+1;}
		else if (bsum < tot) {bsum += b[i]; br=i+1;}
		else {csum += c[i]; cr=i+1;}
	}
	if (asum>=tot && bsum>=tot && csum>=tot){
		cout << "1 " << ar << ' ' << ar+1 << ' ' << br << ' ' << br+1 << ' ' << cr << '\n';
		return;
	}

	asum=0, bsum=0, csum=0;
	ar=0, br=0, cr=0;
	F0R(i, n){
		if(asum<tot){ asum += a[i]; ar=i+1;}
		else if (csum < tot) {csum += c[i]; cr=i+1;}
		else {bsum += b[i]; br=i+1;}
	}
	if (asum>=tot && bsum>=tot && csum>=tot){
		cout << "1 " << ar << ' ' << cr+1 << ' ' << br << ' ' << ar+1 << ' ' << cr << '\n';
		return;
	}

	asum=0, bsum=0, csum=0;
	ar=0, br=0, cr=0;
	F0R(i, n){
		if(bsum<tot){ bsum += b[i]; br=i+1;}
		else if (asum < tot) {asum += a[i]; ar=i+1;}
		else {csum += c[i]; cr=i+1;}
	}
	if (asum>=tot && bsum>=tot && csum>=tot){
		cout << br+1 << ' ' << ar << ' ' << "1 " <<  br << ' ' << ar+1 << ' ' << cr << '\n';
		return;
	}

	asum=0, bsum=0, csum=0;
	ar=0, br=0, cr=0;
	F0R(i, n){
		if(bsum<tot){ bsum += b[i]; br=i+1;}
		else if (csum < tot) {csum += c[i]; cr=i+1;}
		else {asum += a[i]; ar=i+1;}
	}
	if (asum>=tot && bsum>=tot && csum>=tot){
		cout << cr+1 << ' ' << ar << ' ' << "1 " <<  br << ' ' << br+1 << ' ' << cr << '\n';
		return;
	}

	asum=0, bsum=0, csum=0;
	ar=0, br=0, cr=0;
	F0R(i, n){
		if(csum<tot){ csum += c[i]; cr=i+1;}
		else if (asum < tot) {asum += a[i]; ar=i+1;}
		else {bsum += b[i]; br=i+1;}
	}
	if (asum>=tot && bsum>=tot && csum>=tot){
		cout << cr+1 << ' ' << ar << ' ' << ar+1 << ' ' <<  br << ' ' << "1 " <<  cr << '\n';
		return;
	}

	asum=0, bsum=0, csum=0;
	ar=0, br=0, cr=0;
	F0R(i, n){
		if(csum<tot){ csum += c[i]; cr=i+1;}
		else if (bsum < tot) {bsum += b[i]; br=i+1;}
		else {asum += a[i]; ar=i+1;}
	}
	if (asum>=tot && bsum>=tot && csum>=tot){
		cout << br+1 << ' ' << ar << ' ' << cr+1 << ' ' <<  br << ' ' << "1 " <<  cr << '\n';
		return;
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
