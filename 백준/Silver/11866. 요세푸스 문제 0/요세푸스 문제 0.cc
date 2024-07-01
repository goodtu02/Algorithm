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
  vector<int> circle(n);
  vector<int> result;
  for (int i = 0; i < n; i++) circle[i] = i + 1;
  int idx = k - 1;
  while (true) {
	result.push_back(circle[idx]);
	if (circle.size() == 1) break;
	circle.erase(circle.begin() + idx);
	idx += (k - 1);
	while (true) {
	  if (idx > circle.size() - 1)
		idx -= circle.size();
	  else break;
	}
  }
  cout << '<';
  for (int i = 0; i < n; i++) {
	if (i == n - 1) cout << result[i];
	else cout << result[i] << ", ";
  }
  cout << '>';
  return 0;
}