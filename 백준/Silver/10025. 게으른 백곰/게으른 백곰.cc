#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  int n, k;
  cin >> n >> k;
  map<int, int> ice; //좌표, 개수
  long long result = 0;

  int cdn = 0;
  for (int i = 0; i < n; i++) {
    int g, x;
    cin >> g >> x;
    ice.insert(make_pair(x, g));
    cdn = max(cdn, x);
  }
  int left = 0;
  int right = 0;

  for (right; right < 2 * k + 1; right++)
    //슬라이딩 윈도우 생성
    result += ice.find(right)->second;
  long long window = result;
  for (right; right <= cdn; right++) {
    window += ice.find(right)->second;
    window -= ice.find(left)->second;
    left++;
    result = max(result, window);
  }
  cout << result;
  return 0;
}
