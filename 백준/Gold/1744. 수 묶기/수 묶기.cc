#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  int n;
  cin >> n;
  priority_queue<int, vector<int>, greater<>> negative; //음수 오름차순 정렬
  priority_queue<int> positive; //양수 내림차순 정렬

  int zero = 0; //0
  int one = 0; //1
  for (int i = 0; i < n; i++) {
	int a;
	cin >> a;
	if (a < 0) negative.push(a);
	else if (a == 0) zero++;
	else if (a == 1) one++;
	else positive.push(a);
  }
  long long sum = 0;
  while (negative.size() > 1) //두 음수 묶기
  {
	int a = negative.top();
	negative.pop();
	int b = negative.top();
	negative.pop();
	sum += a * b;
  }
  while (zero > 0 && !negative.empty()) //처리 되지 않은 음수 0과 묶기
  {
	if (negative.size() == 1 && negative.top() == 1) break;
	negative.pop();
	zero--;
  }
  while (positive.size() > 1) //1보다 큰 두 양수 묶기
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
	sum += negative.top();
	negative.pop();
  }
  for (int i = 0; i < ms; i++) {
	sum += positive.top();
	positive.pop();
  }
  cout << sum + one;
  return 0;
}