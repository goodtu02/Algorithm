#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  deque<pair<int, int>> num; //인덱스, 값
  //덱의 맨앞의 숫자 > 다음 숫자 : 덱 맨앞 x 다음 숫자 맨앞
  //덱의 맨 뒤 숫자 < 다음 숫자 : 스킵
  //덱의 맨 뒤 숫자 > 다음 숫자 : 큰 수 전부 pop 후 다음 숫자 push
  vector<int> res;
  int n, l;
  cin >> n >> l;
  //num.push_back(make_pair(0, 5000001));
  for (int i = 0; i < n; i++) {
	int a;
	cin >> a;
	//if (a < num.front().second) num.push_front(make_pair(i, a));
	//if (num.size()<=1)num.push_back(make_pair(i, a));
	while (true) {
	  if (num.empty() || a > num.back().second) break; //deque에서 끝까지 전부 다 지워버리면 오류
	  num.pop_back();
	}
	num.push_back(make_pair(i, a));

	while (true) //슬라이딩 윈도우 크기 조정
	{
	  if (i - num.front().first > l - 1)
		num.pop_front();
	  else break;
	}
	res.push_back(num.front().second);
  }
  for (int i : res) {
	cout << i << ' ';
  }
  return 0;
}