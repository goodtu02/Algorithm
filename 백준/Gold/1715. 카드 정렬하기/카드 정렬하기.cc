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
  priority_queue<int, vector<int>, greater<>> card;
  for (int i = 0; i < n; i++) {
	int a;
	cin >> a;
	card.push(a);
  }
  int result = 0, sum;
  while (card.size() > 1) {
	int a, b;
	a = card.top();
	card.pop();
	b = card.top();
	card.pop();
	sum = (a + b);
	result += sum;
	card.push(sum);
  }
  cout << result;
  return 0;
}