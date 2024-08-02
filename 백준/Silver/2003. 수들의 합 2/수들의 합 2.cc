#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  int n, k;
  cin >> n >> k;
  vector<int> list;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    list.push_back(a);
  }
  int count = 0;
  for (auto left = list.begin(); left != list.end(); ++left) {
    auto right = left + 1;
    long long sum = *left;
    if (sum == k) {
      count++;
      continue;
    }
    while (right != list.end()) {
      sum += *right;
      if (sum > k) break;
      if (sum == k) {
        count++;
        break;
      }
      ++right;
    }
  }
  cout << count;
  return 0;
}
