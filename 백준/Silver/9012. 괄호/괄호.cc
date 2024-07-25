#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    bool possible = true;
    int count = 0;
    string str;
    cin >> str;
    for (char &c : str) {
      if (c == '(') count++;
      if (c == ')') count--;
      if (count < 0) break;
    }
    if (count != 0) possible = false;
    if (possible) cout << "YES" << '\n';
    else cout << "NO" << '\n';
  }
  return 0;
}
