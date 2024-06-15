#include <iostream>
#include <stack>
#include <algorithm>
#include <string>

#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  stack<int> st;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
	int a, b;
	cin >> a;
	if (a == 1) {
	  cin >> b;
	  st.push(b);
	} else if (a == 2) {
	  if (!st.empty()) {
		cout << st.top() << '\n';
		st.pop();
	  } else cout << -1 << '\n';
	} else if (a == 3) cout << st.size() << '\n';
	else if (a == 4) {
	  if (st.empty()) cout << 1 << '\n';
	  else cout << 0 << '\n';
	} else if (a == 5) {
	  if (!st.empty())
		cout << st.top() << '\n';
	  else cout << -1 << '\n';
	}
	//cout << '\n';
  }
  return 0;
}