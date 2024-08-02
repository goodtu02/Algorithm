#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

bool compare(long long a, long long b) {
  return abs(a) < abs(b);
}
int main() {
  fast_io;
  int n;
  cin >> n;
  vector<long long> list;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    list.push_back(x);
  }
  long long m = 2000000000;
  pair<long long, long long> p;
  sort(list.begin(), list.end(), compare);
  for (int i = 0; i < n - 1; i++) {
    if (m > abs(list[i] + list[i + 1])) {
      p = make_pair(list[i], list[i + 1]);
      m = abs(list[i] + list[i + 1]);
    }
  }
  cout << min(p.first, p.second) << ' ' << max(p.first, p.second);
  return 0;
}
