#include <iostream>
#include <vector>
#include <algorithm>

#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)

using namespace std;

vector<vector<int>> graph;
vector<int> visited; //미방문 0, 집합 1,2
vector<bool> vis;
bool type;

void dfs(int node, int set) {
  if (set == visited[node]) {
	type = false;
	return;
  }
  if (visited[node] == 0) {
	if (set == 1) visited[node] = 2;
	else if (set == 2) visited[node] = 1;
	vis[node] = true;
	for (auto& i : graph[node])
	  dfs(i, visited[node]);
  } else return;
}
int main() {
  fast_io;
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
	int v, e;
	cin >> v >> e;
	graph.clear();
	visited.clear();
	vis.clear();
	graph.resize(v + 1);
	visited.resize(v + 1, 0);
	vis.resize(v + 1, false);
	type = true;
	for (int j = 0; j < e; j++) {
	  int a, b;
	  cin >> a >> b;
	  graph[a].push_back(b);
	}
	for (int j = 1; j <= v; j++) {
	  if (!type) break;
	  if (vis[j]) continue;
	  dfs(j, 1);
	  fill(visited.begin(), visited.end(), 0);
	}
	if (type) cout << "YES" << '\n';
	else cout << "NO" << '\n';
  }
  return 0;
}