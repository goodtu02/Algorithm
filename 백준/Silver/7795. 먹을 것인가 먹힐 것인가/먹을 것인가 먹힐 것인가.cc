#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  int t;
  cin >> t;
  vector<int> lista;
  vector<int> listb;
  for (int i = 0; i < t; i++) {
    int n, m;
    cin >> n >> m;
    lista.resize(n);
    listb.resize(m);
    int count = 0;
    for (int j = 0; j < n; j++) cin >> lista[j];
    for (int j = 0; j < m; j++) cin >> listb[j];
    sort(listb.begin(), listb.end(), greater());
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        if (lista[j] > listb[k]) {
          count += (m - k);
          break;
        }
      }
    }
    cout << count << '\n';
    lista.clear();
    listb.clear();
  }
  return 0;
}
