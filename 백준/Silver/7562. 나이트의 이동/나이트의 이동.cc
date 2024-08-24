#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  int t;
  cin >> t;
  for (int j = 0; j < t; j++) {
    int l;
    cin >> l;
    int curx, cury;
    cin >> curx >> cury;
    int targetx, targety;
    cin >> targetx >> targety;
    int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[] = {2, 1, -1, -2, 2, 1, -1, -2};
    queue<pair<int, int>> chess;
    vector<int> distance(l * l, 0);
    vector<bool> visited(l * l, true);
    chess.push({curx, cury});
    while (!chess.empty()) {
      int x = chess.front().first;
      int y = chess.front().second;
      chess.pop();
      visited[x + y * l] = false;
      if (x == targetx && y == targety) {
        cout << distance[x + y * l] << '\n';
        break;
      }
      for (int i = 0; i < 8; i++) {
        if (x + dx[i] >= 0 && x + dx[i] < l && y + dy[i] >= 0 && y + dy[i] < l) {
          int temp = (y + dy[i]) * l + x + dx[i];
          if (visited[temp]) {
            chess.push({x + dx[i], y + dy[i]});
            distance[temp] = distance[x + y * l] + 1;
            visited[temp] = false;
          }
        }
      }
    }
  }
  return 0;
}
