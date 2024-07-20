#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)

using namespace std;

vector<bool> visited;
vector<vector<int>> node;

int cnt;

void bfs(int s) {
  cnt = 0;
  queue<int> visit;
  visit.push(s);
  visited[s] = true;
  while (!visit.empty()) {
	for (auto& i : node[visit.front()]) {
	  if (!visited[i]) {
		visit.push(i);
		cnt++;
		visited[i] = true;
	  }
	}
	visit.pop();
  }
}
int main() {
  fast_io;
  int n, m;
  cin >> n >> m;
  vector<int> result;
  node.resize(n + 1);
  visited.resize(n + 1, false);
  for (int i = 0; i < m; i++) {
	int a, b;
	cin >> a >> b;
	node[b].push_back(a);
  }

  for (int i = 0; i < n + 1; i++) {
	bfs(i);
	fill(visited.begin(), visited.end(), false);
	result.push_back(cnt);
  }
  for (int i = 1; i < n + 1; i++) {
	if (*max_element(result.begin(), result.end()) == result[i])
	  cout << i << '\n';
  }
  return 0;
}