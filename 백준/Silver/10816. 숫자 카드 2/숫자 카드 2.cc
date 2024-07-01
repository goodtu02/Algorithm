#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  int n, m;
  cin >> n;
  vector<int> card;
  vector<int> num(20000001, 0);
  for (int i = 0; i < n; i++) //증복 카드 처리
  {
	int a;
	cin >> a;
	card.push_back(a);
	num[a + 10000000]++;
  }
  cin >> m;
  vector<int> search(m);
  vector<int> count(m, 0);
  for (int i = 0; i < m; i++) cin >> search[i];
  sort(card.begin(), card.end());
  for (int i = 0; i < m; i++) {
	int start = 0;
	int end = card.size() - 1;
	int target = search[i];
	while (start <= end) { //이분탐색
	  int mid = (start + end) / 2;
	  if (card[mid] < target) start = mid + 1;
	  else if (card[mid] > target) end = mid - 1;
	  else {
		count[i] = num[target + 10000000];
		break;
	  }
	}
  }
  for (int& i : count) cout << i << ' ';
  return 0;
}