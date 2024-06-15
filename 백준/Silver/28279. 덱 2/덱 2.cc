#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  deque<int> deq;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
	int a, b;
	cin >> a;
	if (a == 1) {
	  cin >> b;
	  deq.push_front(b);
	} else if (a == 2) {
	  cin >> b;
	  deq.push_back(b);
	} else if (a == 3) {
	  if (deq.empty()) cout << -1 << '\n';
	  else {
		cout << deq.front() << '\n';
		deq.pop_front();
	  }
	} else if (a == 4) {
	  if (deq.empty()) cout << -1 << '\n';
	  else {
		cout << deq.back() << '\n';
		deq.pop_back();
	  }
	} else if (a == 5) cout << deq.size() << '\n';
	else if (a == 6) {
	  if (deq.empty()) cout << 1 << '\n';
	  else cout << 0 << '\n';
	} else if (a == 7) {
	  if (deq.empty()) cout << -1 << '\n';
	  else cout << deq.front() << '\n';
	} else if (a == 8) {
	  if (deq.empty()) cout << -1 << '\n';
	  else cout << deq.back() << '\n';
	}
  }
  return 0;
}