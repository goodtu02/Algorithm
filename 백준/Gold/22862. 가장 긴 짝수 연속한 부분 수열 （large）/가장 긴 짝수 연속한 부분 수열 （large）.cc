#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  int n, k;
  cin >> n >> k;
  vector<int> list;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    list.push_back(x);
  }
  int result = 0;
  int even = 0;
  int odd = 0;
  auto left = list.begin();
  auto right = left;
  while (right != list.end()) {
    if (*right % 2 == 0) even++;
    else odd++;
    while (odd > k) {
      if (left > right) break;
      if (*left % 2 == 0) even--;
      else odd--;
      ++left;
    }
    result = max(result, even);
    ++right;
  }
  cout << result;
  return 0;
}
