#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  vector<vector<int>> apt;
  apt.resize(15, vector<int>(15));
  for (int i = 0; i < 15; i++) apt[0][i] = i;

  for (int i = 1; i < 15; i++) apt[0][i] = apt[0][i - 1] + i;
  for (int i = 1; i < 15; i++) {
    apt[i][0] = 0;
    int sum = 0;
    for (int j = 1; j < 15; j++) {
      sum += apt[i - 1][j];
      apt[i][j] = sum;
    }
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int k, n;
    cin >> k >> n;
    cout << apt[k-1][n] << '\n';
  }
  return 0;
}
