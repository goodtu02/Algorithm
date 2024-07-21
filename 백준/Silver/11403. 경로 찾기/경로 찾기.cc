#include <iostream>
#include <vector>
#include <algorithm>

#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)

using namespace std;

vector<vector<int>> graph; //인접 리스트
vector<vector<int>> result; //인접 행렬
vector<bool> visited;

int start;

void dfs(int node) {
  if (!visited[node]) {
	visited[node] = true;
	for (auto i : graph[node]) {
	  result[start][i] = 1;
	  dfs(i);
	}
  } else return;
}
int main() {
  fast_io;
  int n;
  cin >> n;
  graph.resize(n);
  result.resize(n, vector<int>(n, 0));
  visited.resize(n, false);
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	  int a;
	  cin >> a;
	  if (a == 1) graph[i].push_back(j);
	}
  }
  for (int i = 0; i < n; i++) {
	start = i;
	dfs(i);
	fill(visited.begin(), visited.end(), false);
  }
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) cout << result[i][j] << ' ';
	cout << '\n';
  }

  return 0;
}