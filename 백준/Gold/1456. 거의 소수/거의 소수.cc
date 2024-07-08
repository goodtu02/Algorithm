#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  long long a, b;
  cin >> a >> b;
  vector<int> sieve(sqrt(b) + 1); //에라토스테네스의 체
  for (int i = 2; i <= sqrt(b); i++) sieve[i] = i;
  for (int j = 2; j <= sqrt(sqrt(b)); j++) {
	if (sieve[j] == 0) continue;
	for (int i = j * j; i < sieve.size(); i += j) {
	  if (sieve[i] % j == 0) sieve[i] = 0;
	}
  }
  sort(sieve.begin(), sieve.end(), greater());
  sieve.erase(remove(sieve.begin(), sieve.end(), 0), sieve.end());
  int count = 0;
  for (int i : sieve) {
	long long k = i;
	while ((double) i <= (double) b / (double) k) {
	  if ((double) i >= (double) a / (double) k) count++;
	  k *= i;
	}
  }
  cout << count;
  return 0;
}