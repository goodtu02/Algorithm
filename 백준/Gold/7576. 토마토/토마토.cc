#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  int n, m;
  cin >> n >> m;
  vector<int> start;
  vector<vector<int>> tomato(n * m);
  vector<bool> check(n * m, false);
  vector<int> distance(n * m, 0);
  vector<int> t(n * m, 0);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      int now = i * n + j;
      if (x == -1) {
        check[now] = true;
        t[now] = -1;
        continue;
      }
      if (x == 1) start.push_back(now);
      if (i > 0 && t[now - n] != -1) {
        tomato[now - n].push_back(now);
        tomato[now].push_back(now - n);
      }
      if (j > 0 && t[now - 1] != -1) {
        tomato[now - 1].push_back(now);
        tomato[now].push_back(now - 1);
      }
      if (i < m - 1 && t[now + n] != -1) {
        tomato[now + n].push_back(now);
        tomato[now].push_back(now + n);
      }
      if (j < n - 1 && t[now + 1] != -1) {
        tomato[now + 1].push_back(now);
        tomato[now].push_back(now + 1);
      }
    }
  }
  queue<int> visit;
  for (int i : start) {
    visit.push(i);
    check[i] = true;
  }

  while (!visit.empty()) {
    for (int j : tomato[visit.front()]) {
      if (!check[j]) {
        visit.push(j);
        check[j] = true;
        distance[j] = distance[visit.front()] + 1;
      }
    }
    visit.pop();
  }
  if (find(check.begin(), check.end(), false) == check.end()) cout << *max_element(distance.begin(), distance.end());
  else cout << -1;
  return 0;
}
