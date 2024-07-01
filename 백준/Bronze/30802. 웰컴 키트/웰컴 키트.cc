#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  int n, t, p;
  int shirt = 0, pen;
  cin >> n;
  vector<int> size(6);
  for (int i = 0; i < 6; i++) cin >> size[i];
  cin >> t >> p;
  for (int& i : size) {
	int temp = i / t + 1;
	if (i % t == 0) shirt += i / t;
	else shirt += i / t + 1;
  }
  pen = n / p;
  cout << shirt << '\n';
  cout << pen << ' ' << n - p * pen;
  return 0;
}