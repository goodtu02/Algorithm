#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
#define ll long long

using namespace std;

ll eulerphi(ll k) { //오일러 피 함수
  ll disjoint = k; //서로소 개수
  if (disjoint == 1) {
	disjoint = 0;
	return disjoint;
  }
  for (ll i = 2; i <= sqrt(k); i++) {
	if (k % i == 0) disjoint = disjoint - disjoint / i;
	while (k % i == 0) k /= i;
  }
  if (k > 1) disjoint = disjoint - disjoint / k;
  return disjoint;
}
int main() {
  fast_io;
  vector<ll> list;
  ll n = 1;
  while (true) {
	cin >> n;
	if (n == 0) break;
	list.push_back(n);
  }

  for (ll& i : list) cout << eulerphi(i) << '\n';

  return 0;
}