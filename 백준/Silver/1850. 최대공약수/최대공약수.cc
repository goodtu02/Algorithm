#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
#define ll long long

using namespace std;

ll gcd(ll a, ll b) {
  ll r = b % a;
  if (r == 0) return a;
  else return gcd(r, a);
}

int main() {
  fast_io;
  ll a, b;
  cin >> a >> b;
  string g;
  ll r = gcd(a, b);
  for (ll i = 0; i < r; i++) g.push_back('1');
  for (char& i : g) cout << i;
  return 0;
}