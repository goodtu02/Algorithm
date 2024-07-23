#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

vector<int> unionset;

int find(int x) {
  if (unionset[x] == x) return x;
  return unionset[x] = find(unionset[x]);
}
void union_(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y) unionset[max(x, y)] = unionset[min(x, y)];
}
int main() {
  fast_io;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= n; i++) unionset.push_back(i);
  for (int i = 0; i < m; i++) {
    int k;
    int a, b;
    cin >> k >> a >> b;
    if (k == 0) union_(max(a, b), min(a, b));
    if (k == 1) {
      if (find(a) == find(b)) cout << "YES" << '\n';
      else cout << "NO" << '\n';
    }
  }

  return 0;
}
