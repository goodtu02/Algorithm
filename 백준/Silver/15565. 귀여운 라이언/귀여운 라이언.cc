#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  int n, k;
  cin >> n >> k;
  vector<int> list;
  int lion = 0;
  int result = 1000001;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    list.push_back(x);
  }
  auto left = list.begin();
  auto right = left;
  for (right; right != list.end(); ++right) {
    if (*right == 1) lion++;
    while (lion > k) {
      if (*left == 1) lion--;
      ++left;
    }
    while (lion == k) {
      result = min(result, (int) (right - left) + 1);
      if (*left == 1) break;
      ++left;
    }
  }
  if (result == 1000001) cout << -1;
  else cout << result;
  return 0;
}
