#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  int w, g;
  cin >> w >> g;
  string part;
  string full;
  cin >> part >> full;
  int count = 0;
  vector<int> partalp(52, 0);
  vector<int> fullalp(52, 0);
  for (char &c : part) {
    if (isupper(c)) partalp[(int) c - 65]++;
    else partalp[(int) c - 71]++;
  }
  auto left = full.begin();
  auto right = left;
  for (int i = 0; i < w; i++) {
    if (isupper(*right)) fullalp[(int) *right - 65]++;
    else fullalp[(int) *right - 71]++;
    ++right;
  }
  --right;
  while (right != full.end()) {
    if (partalp == fullalp) count++;
    ++right;
    if (right == full.end()) break;
    if (isupper(*right)) fullalp[(int) *right - 65]++;
    else fullalp[(int) *right - 71]++;
    if (isupper(*left)) fullalp[(int) *left - 65]--;
    else fullalp[(int) *left - 71]--;
    ++left;
  }
  cout << count;
  return 0;
}
