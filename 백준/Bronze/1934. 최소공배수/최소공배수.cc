#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)

using namespace std;

int gcd(int x, int y) //유클리드 호재법
{
  int r = y % x;
  if (r == 0) return x;
  else return gcd(r,x);
}
int main() {
  fast_io;
  int t;
  cin >> t;
  vector<int> gcdd;
  for (int i = 0; i < t; i++) {
	int a, b;
	cin >> a >> b;
	gcdd.push_back(a * b / gcd(a, b));
  }
  for (int i : gcdd) cout << i << '\n';
  return 0;
}