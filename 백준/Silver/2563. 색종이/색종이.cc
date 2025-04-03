#include <iostream>
#include <vector>
#include <algorithm>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;
int main() {
  fast_io;

  vector<vector<int>> pcs(100, vector<int>(100));
  int n;
  cin >> n;
  int result = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    for (int p = 100 - y - 10; p < 100 - y; p++) {
      for (int k = x; k < x + 10; k++) {
        pcs[p][k] = 1;
      }
    }
  }
  for (int i = 0; i < 100; i++) {
    for (int p = 0; p < 100; p++) {
      if (pcs[i][p] == 1) result++;
    }
  }
  cout << result;
  return 0;
}