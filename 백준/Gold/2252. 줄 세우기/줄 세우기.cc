#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  int n, m;
  cin >> n >> m;
  vector<vector<int>> list(n);
  vector<int> edge(n, 0);
  vector<bool> visit(n, false);
  vector<int> result;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    list[a-1].push_back(b-1); //유향 그래프
    edge[b-1]++;
  }
  while (true) {
    int idx = -1;
    for (int i = 0; i < n; i++) {
      if (edge[i] == 0 && !visit[i]) {
        idx = i;
        result.push_back(idx);
        break;
      }
    }
    if (idx == -1) break;
    visit[idx] = true;
    for (int i : list[idx]) edge[i]--;
  }
  for (int i : result) cout << i + 1 << ' ';
  return 0;
}
