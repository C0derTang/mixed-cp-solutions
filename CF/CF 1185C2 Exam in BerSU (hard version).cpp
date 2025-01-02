#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    
    // for every additional element with index i and value v
    // find the minimum number of elements to remove from the set containing element values
    // with indices 0 to i-1 so that the sum of the elements in the set + v <=m

    // so we can keep running set of removed elements, and add or remove as needed?

    int n, m;
    cin >> n >> m;
    // ima attempt online queries
    // oh wait the elements are only from 1-100
    // bruh
    // frequency array, walk down, and then bsearch on the one where it changes lmfao
    // no way i walked all day around beijing and only saw this constraint now
    // goddammit
    vector<int> freq(101);
    int sum = 0;
    while(n--){
        int v; cin >> v;
        sum += v;
        int rem=0, rsum=0;
        for(int i=100; i>0; --i){
            if (sum < m) break;
            if (sum-rsum-i*freq[i] > m){
                rem += freq[i];
                rsum += i*freq[i];
            }else{
                //wait u can just alg
                rem += (sum-rsum-m+(i-1))/i;
                break;
            }
        }
        cout << rem << ' ';
        ++freq[v];
    }
}
