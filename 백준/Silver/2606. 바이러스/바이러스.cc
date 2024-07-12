#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>

#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)

using namespace std;

static vector<vector<int>> comp;
static vector<bool> visited;
static queue<int> vis;
static int cnt = 0;

void bfs(int x) {
  vis.push(x);
  while (!vis.empty()) {
	int k = vis.front();
	visited[k] = true;
	vis.pop();
	cnt++;
	for (int i : comp[k]) {
	  if (!visited[i]) {
		vis.push(i);
		visited[i] = true;
	  }
	}
  }
}
int main() {
  fast_io;
  int n, m;
  cin >> n >> m;
  comp = vector<vector<int>>(n);
  visited = vector<bool>(n, false);
  for (int i = 0; i < m; i++) {
	int a, b;
	cin >> a >> b;
	comp[a - 1].push_back(b - 1);
	comp[b - 1].push_back(a - 1);
  }
  bfs(0);
  cout << cnt - 1;
  return 0;
}