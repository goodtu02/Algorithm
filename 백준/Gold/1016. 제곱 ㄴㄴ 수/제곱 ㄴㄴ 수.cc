#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
#define ll long long
using namespace std;
int main() {
  fast_io;
  long long min, max;
  cin >> min >> max;
  set<ll> sieve;
  //제곱 ㅇㅇ 수 구해서 범위에서 감하기
  for (ll i = 2; i < (ll) sqrt(max) + 1; i++) { //root n
	ll square = i * i;
	if (square > max) break;
	if (sieve.find(square) != sieve.end()) continue; //logn
	ll j;
	if (square < min) j = min / square * square;
	else j = square;
	for (; j <= max; j += square) {
	  if (j >= min) sieve.insert(j);
	}
  }
  if (sieve.empty()) cout << max - min + 1;
  else cout << max - min + 1 - sieve.size();
  return 0;
}