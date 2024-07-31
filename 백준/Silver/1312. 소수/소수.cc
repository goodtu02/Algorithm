#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  int a, b, n;
  cin >> a >> b >> n;
  for (int i = 0; i < n; i++) {
    a = a % b;
    a *= 10;
  }
  cout << a/b;
  return 0;
}
