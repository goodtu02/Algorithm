#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;
#define ll long long

ll gcd(ll a, ll b) {
  ll r = a % b;
  if (r == 0) return b;
  return gcd(b, r);
}
int main() {
  fast_io;
  ll a, b;
  cin >> a >> b;
  cout << a * b / gcd(a, b);
  return 0;
}
