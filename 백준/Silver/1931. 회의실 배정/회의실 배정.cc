#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

template<typename T>
bool cmp(pair<T, T> a, pair<T, T> b) { //종료 시간 기준 오름차순 정렬
  if (a.second < b.second) return true;
  else if (a.second == b.second) {
	if (a.first < b.first) return true;
	else return false;
  } else return false;
}
int main() {
  fast_io;
  int n;
  cin >> n;
  vector<pair<long long, long long>> time;
  for (int i = 0; i < n; i++) {
	long long a, b;
	cin >> a >> b;
	time.push_back(make_pair(a, b));
  }
  sort(time.begin(), time.end(), cmp<long long>);
  //for (auto& i : time) cout << i.first << ' ' << i.second << '\n';
  long long last = 0, result = 0;
  for (auto& i : time) {
	if (i.first >= last) {
	  last = i.second;
	  result++;
	}
  }
  cout << result;
  return 0;
}