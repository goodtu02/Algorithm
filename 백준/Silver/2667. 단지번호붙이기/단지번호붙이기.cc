#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

vector<vector<int>> house;
vector<bool> visited;
vector<int> result;
int num;
void dfs(int node) {
  visited[node] = false;
  num++;
  for (int i : house[node]) {
    if (visited[i]) dfs(i);
  }

}
int main() {
  fast_io;
  int n;
  cin >> n;
  house.resize(n * n);
  visited.resize(n * n, false);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      int x = atoi(&c);

      if (x == 0) continue;
      int now = i * n + j;
      visited[now] = true;
      if (i > 0) {
        house[now - n].push_back(now);
        house[now].push_back(now - n);
      }
      if (j > 0) {
        house[now - 1].push_back(now);
        house[now].push_back(now - 1);
      }
      if (i < n - 1) {
        house[now + n].push_back(now);
        house[now].push_back(now + n);
      }
      if (j < n - 1) {
        house[now + 1].push_back(now);
        house[now].push_back(now + 1);
      }
    }
  }
  for (int i = 0; i < n * n; i++) {
    num = 0;
    if (visited[i]) dfs(i);
    else continue;
    result.push_back(num);
  }
  sort(result.begin(), result.end());
  cout << result.size() << '\n';
  for (int i : result) cout << i << '\n';

  return 0;
}
