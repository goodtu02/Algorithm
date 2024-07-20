#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)

using namespace std;

vector<int> length;
vector<bool> visited;
vector<vector<int>> road;

void bfs(int x) {
  queue<int> visit;
  visit.push(x);
  visited[x] = true;
  while (!visit.empty()) {
	for (auto& i : road[visit.front()]) {
	  if (!visited[i]) {
		visit.push(i);
		length[i] = length[visit.front()] + 1;
		visited[i] = true;
	  }
	}
	visit.pop();
  }
}
int main() {
  fast_io;
  int n, m, k, x;
  cin >> n >> m >> k >> x;
  road = vector<vector<int>>(n + 1);
  visited = vector<bool>(n + 1, false);
  length = vector<int>(n + 1, 0);
  for (int i = 0; i < m; i++) {
	int a, b;
	cin >> a >> b;
	road[a].push_back(b);
  }
  bfs(x);
  vector<int> result;
  for (int i = 0; i < n + 1; i++) {
	if (length[i] == k) result.push_back(i);
  }
  if (result.empty()) cout << -1;
  else {
	sort(result.begin(), result.end());
	for (int& i : result) cout << i << '\n';
  }
  return 0;
}