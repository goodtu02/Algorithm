#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  int k;
  cin >> k;
  vector<int> n; //음수
  vector<int> p; //1보다 큰 양수
  queue<int> negative; //음수
  stack<int> positive; //1보다 큰 양수 정렬
  int zero = 0; //0
  int one = 0; //1
  for (int i = 0; i < k; i++) {
	int a;
	cin >> a;
	if (a < 0) n.push_back(a);
	else if (a == 0) zero++;
	else if (a == 1) one++;
	else p.push_back(a);
  }
  long long sum = 0;
  sort(n.begin(), n.end());
  for (int& i : n) negative.push(i);
  sort(p.begin(), p.end());
  for (int& i : p) positive.push(i);
  while (negative.size() > 1) //두 음수 묶기 //원소가 없거나 1개 남으면 종료
  {
	int a = negative.front();
	negative.pop();
	int b = negative.front();
	negative.pop();
	sum += a * b;
  }
  while (zero > 0 && !negative.empty()) //처리 되지 않은 음수 0과 묶기
  {
	if (negative.size() == 1 && negative.front() == 1) break;
	negative.pop();
	zero--;
  }
  while (positive.size() > 1) //1보다 큰 두 양수 묶기 //원소가 없거나 1개 남으면 종료
  {
	int a = positive.top();
	positive.pop();
	int b = positive.top();
	positive.pop();
	sum += a * b;
  }
  int ps = negative.size();
  int ms = positive.size();
  for (int i = 0; i < ps; i++) {
	sum += negative.front();
	negative.pop();
  }
  for (int i = 0; i < ms; i++) {
	sum += positive.top();
	positive.pop();
  }
  cout << sum + one;
  return 0;
}