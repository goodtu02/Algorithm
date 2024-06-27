#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  int a, b, c;
  cin >> a >> b >> c;
  cout << a + b - c << '\n';
  string sum = to_string(a) + to_string(b);
  cout << stoi(sum) - c;
  return 0;
}