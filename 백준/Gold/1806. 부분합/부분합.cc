#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
#define int long long
  fast_io;
  int n, s;
  cin >> n >> s;
  vector<int> list;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    list.push_back(a);
  }
  int length = 100000000;
  auto left = list.begin();
  int sum = 0;
  for (auto right = left; right < list.end(); ++right) {
    sum+=*right;
    while (sum >= s) {
      length = min(length, (int)(right - left) + 1);
      sum -= *left;
      ++left;
    }
  }
  if (length == 100000000) cout << 0;
  else cout << length;
  return 0;
}
