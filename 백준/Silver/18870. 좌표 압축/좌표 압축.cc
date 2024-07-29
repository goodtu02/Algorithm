#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  int n;
  cin >> n;
  map<int, int> sorted;
  vector<int> list;
  vector<int> result(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    sorted.insert(make_pair(a, i));
    list.push_back(a);
  }
  int idx = 0;
  for (auto &iter : sorted) {
    iter.second = idx;
    idx++;
  }
  for (int i : list) {
    auto iter = sorted.find(i);
    cout << iter->second << ' ';
  }
  return 0;
}
