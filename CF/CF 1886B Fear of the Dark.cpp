#include <bits/stdc++.h>
using namespace std;

#define double long double
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

const int dulo = 998244353;



bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

double dist(int x1, int y1, int x2, int y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void solve(){
    double px, py, ax, ay, bx, by;
    cin >> px >> py >> ax >> ay >> bx >> by;
    double ans = 100000;
    ans = min(max(dist(0,0,ax,ay), dist(px,py,ax,ay)),max(dist(0,0,bx,by), dist(px,py,bx,by)));
    
    ans = min(ans, max(dist(ax,ay,bx,by)/2, max(dist(0,0,ax,ay), dist(px,py,bx,by))));
    ans = min(ans, max(dist(ax,ay,bx,by)/2, max(dist(0,0,bx,by), dist(px,py,ax,ay))));
        
    cout << setprecision(15) << ans << '\n';

}


signed main() {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin.tie(NULL) -> sync_with_stdio(false);
    
    int t; cin >> t;
    while(t--){
        solve();
    }
}