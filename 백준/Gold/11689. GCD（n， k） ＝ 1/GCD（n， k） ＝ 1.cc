#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
#define ll long long
using namespace std;
int main() {
  fast_io;
  ll n;
  cin >> n;
  ll disjoint = n; //서로소 개수
  for (ll i = 2; i <= sqrt(n); i++) { //오일러 피 함수
	if (n % i == 0) disjoint = (disjoint - disjoint / i);
	while (n % i == 0) n /= i;
  }
  if (n > 1) disjoint = disjoint - disjoint / n;
  cout << disjoint;
  return 0;
}