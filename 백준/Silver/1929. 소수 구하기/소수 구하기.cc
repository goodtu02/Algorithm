#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  int m, n;
  cin >> m >> n;
  vector<int> sieve(n + 1); //에라토스테네스의 체
  for (int i = 2; i <= n; i++) sieve[i] = i;
  for (int j = 2; j <= sqrt(n); j++) {
	if (sieve[j] == 0) continue;
	for (int i = j * j; i < sieve.size(); i += j) {
	  if (sieve[i] % j == 0) sieve[i] = 0;
	}
  }
  for (int i : sieve) {
	if (i >= m && i <= n) cout << i << '\n';
  }
  return 0;
}