#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

bool comp(const pair<string, int> &p1, const pair<string, int> &p2) {
  if (p1.second > p2.second) return true;
  return false;
}
int main() {
  fast_io;
  vector<int> year;
  vector<pair<string, int>> name;

  for (int i = 0; i < 3; i++) {
    int a, b;
    string c;
    cin >> a >> b >> c;
    year.push_back(b % 100);
    name.push_back(make_pair(c, a));
  }
  sort(year.begin(), year.end());
  for (int i : year) cout << i;
  cout << '\n';
  sort(name.begin(), name.end(), comp);
  for (auto &i : name) {
    cout << i.first[0];
  }

  return 0;
}
