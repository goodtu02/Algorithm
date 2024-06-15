#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  queue<int> q;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
	string a;
	int b;
	cin >> a;
	if (a == "push") {
	  cin >> b;
	  q.push(b);
	} else if (a == "pop") {
	  if (q.empty()) cout << -1 << '\n';
	  else {
		cout << q.front() << '\n';
		q.pop();
	  }
	} else if (a == "front") {
	  if (!q.empty()) cout << q.front() << '\n';
	  else cout << -1 << '\n';
	} else if (a == "back") {
	  if (!q.empty()) cout << q.back() << '\n';
	  else cout << -1 << '\n';
	} else if (a == "size") cout << q.size() << '\n';
	else if (a == "empty") {
	  if (q.empty())
		cout << 1 << '\n';
	  else cout << 0 << '\n';
	}
  }
  return 0;
}