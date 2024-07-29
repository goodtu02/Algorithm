#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int gcd(int a, int b) {
  int r = b % a;
  if (r == 0) return a;
  return gcd(r, a);
}

int main() {
  fast_io;
  int n, s;
  cin >> n >> s;
  vector<int> location;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a - s >= 0) location.push_back(a - s);
    else location.push_back(s - a);
  }
  int g = location[0];
  for (int i = 1; i < location.size(); i++) {
    g = gcd(g, location[i]);
  }
  cout << g;
  return 0;
}
