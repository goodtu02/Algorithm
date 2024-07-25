#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

vector<int> h; //집합 확인 배열

int find(int x) {
  if (h[x] == x) return x; //대표 노드 반환
  return h[x] = find(h[x]); //경로 압축
}
void union_(const vector<int> &party) {
  for (int i = 0; i < party.size() - 1; i++) {
    const int x = find(party[i]);
    const int y = find(party[i + 1]);
    h[max(x, y)] = min(x, y);
  }
}
int main() {
  fast_io;
  int n, m, x;
  cin >> n >> m >> x;
  int result = m;
  for (int i = 0; i <= n; i++) h.push_back(i);
  vector<int> truth;
  vector<vector<int>> party(m); //파티 정보 저장
  for (int i = 0; i < x; i++) {
    int a;
    cin >> a;
    truth.push_back(a);
  }
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    for (int j = 0; j < a; j++) {
      int k;
      cin >> k;
      party[i].push_back(k);
    }
    union_(party[i]);
  }
  for (int i = 0; i < m; i++) {
    bool participate = true;
    for (int k : truth) {
      if (find(k) == find(party[i][0])) {
        //같은 파티의 사람들을 union했으므로 모두 체크할 필요 없음
        participate = false;
        break;
      }
    }
    if (!participate) result--;
  }
  cout << result;
  return 0;
}
