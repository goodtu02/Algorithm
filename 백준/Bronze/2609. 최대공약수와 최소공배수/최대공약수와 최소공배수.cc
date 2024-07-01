#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  int a, b;
  cin >> a >> b;
  int n = min(a, b);
  int m = max(a, b);
  while (true) {
	if (a % n == 0 && b % n == 0) break;
	n--;
  }
  while (true) {
	if (m % a == 0 && m % b == 0) break;
	m++;
  }
  cout << n << '\n' << m;
  return 0;
}