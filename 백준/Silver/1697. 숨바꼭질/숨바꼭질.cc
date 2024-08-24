#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  int n, m;
  cin >> n >> m;
  queue<int> q;
  vector<int> distance(max(n, m) + 2, 0);
  vector<bool> visited(max(n, m) + 2, true);
  q.push(n);
  visited[n] = false;
  while (!q.empty()) {
    int cur = q.front();
    if (cur == m) {
      cout << distance[cur];
      return 0;
    }
    q.pop();
    int a = cur * 2;
    int b = cur + 1;
    int c = cur - 1;
    if (a == m) {
      distance[a] = distance[cur] + 1;
      break;
    } else if (b == m) {
      distance[b] = distance[cur] + 1;
      break;
    } else if (c == m) {
      distance[c] = distance[cur] + 1;
      break;
    }
    if (a < m + 2 && visited[a]) {
      q.push(a);
      distance[a] = distance[cur] + 1;
      visited[a] = false;
    }
    if (b < m + 2 && visited[b]) {
      q.push(b);
      distance[b] = distance[cur] + 1;
      visited[b] = false;
    }
    if (visited[c]) {
      q.push(c);
      distance[c] = distance[cur] + 1;
      visited[c] = false;
    }
  }
  cout << *max_element(distance.begin(), distance.end());
  return 0;
}
