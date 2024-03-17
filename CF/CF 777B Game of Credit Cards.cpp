#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ll long long

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
    cin >> n;
    int s[n], m[n];
    for (int& x : s) {
        char y;
        cin >> y;
        x = y - '0';
    }
    for (int& x : m) {
        char y;
        cin >> y;
        x = y - '0';
    }
    sort(s, s + n);
    sort(m, m + n);
    vector<bool> used_1(n, false), used_2(n, false);
    int min_ans = 0, max_ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            if (s[i] <= m[j] && !used_1[j]) {
                used_1[j] = true;
                ++min_ans;
                break;
            }
        for (int j = 0; j < n; ++j)
            if (s[i] < m[j] && !used_2[j]) {
                used_2[j] = true;
                ++max_ans;
                break;
            }
    }
    cout << n - min_ans << '\n' << max_ans;
}
