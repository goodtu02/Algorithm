#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  int n, k;
  cin >> n >> k;
  int count = 0;
  vector<int> price(n);
  for (int i = 0; i < n; i++) cin >> price[i];
  auto it = price.end() - 1;
  while (true) {
	int share = k / (*it);
	if (share >= 1) {
	  count += share;
	  k -= share * (*it);
	}
	if (k == 0) break;
	it--;
  }
  cout << count;
  return 0;
}