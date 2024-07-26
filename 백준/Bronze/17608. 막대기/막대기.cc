#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  int n;
  cin >> n;
  vector<int> stick;
  int count = 0;
  int height = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    stick.push_back(a);
  }
  for (int i = stick.size() - 1; i >= 0; i--) {
    if (stick[i] > height) {
      count++;
      height = stick[i];
    }
  }
  cout << count;
  return 0;
}
