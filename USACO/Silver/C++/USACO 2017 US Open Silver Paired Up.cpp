#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
vector<pii> V;
int N;

int main()
{
  ifstream fin ("pairup.in");
  ofstream fout ("pairup.out");
  fin >> N;
  for (int i=0; i<N; i++) {
    int x, y;
    fin >> x >> y;
    V.push_back(pii(y,x));
  }
  sort(V.begin(), V.end());
  int M = 0, i=0, j=N-1;
  while (i <= j) {
    int x = min(V[i].second, V[j].second);
    if (i==j) x /= 2;
    M = max(M, V[i].first + V[j].first);
    V[i].second -= x;
    V[j].second -= x;
    if (V[i].second == 0) i++;
    if (V[j].second == 0) j--;
  }
  fout << M << "\n";
  return 0;
}