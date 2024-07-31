#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> chess(n, vector<bool>(m)); //W True B False
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char a;
      cin >> a;
      if (a == 'W') chess[i][j] = true;
      else chess[i][j] = false;
    }
  }
  vector<int> result;
  int row = 0;
  int col = 0;
  while (row + 8 <= n) {
    while (col + 8 <= m) {
      int count = 0;
      bool start = chess[row][col];
      for (int i = row; i < row + 8; i++) {
        for (int j = col; j < col + 8; j++) {
          if (start) {
            if (i % 2 == 0 && j % 2 == 0) {
              if (!chess[i][j]) count++;
            } else if (i % 2 != 0 && j % 2 != 0) {
              if (!chess[i][j]) count++;
            } else { if (chess[i][j]) count++; }
          } else {
            if (i % 2 == 0 && j % 2 == 0) {
              if (chess[i][j]) count++;
            } else if (i % 2 != 0 && j % 2 != 0) {
              if (chess[i][j]) count++;
            } else { if (!chess[i][j]) count++; }
          }
        }
      }
      result.push_back(min(count, 64 - count));
      col++;
    }
    col = 0;
    row++;
  }
  cout << *min_element(result.begin(), result.end());
  return 0;
}
