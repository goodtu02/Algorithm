#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  int t;
  cin >> t;
  unordered_multiset<int> num;
  vector<int> count(11, 0);
  vector<int> k;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    num.insert(n);
    k.push_back(n);
  }
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  while (!q.empty()) {
    if (num.find(q.front()) != num.end()) {
      count[q.front()]++;
    }
    int a = q.front() + 1;
    int b = q.front() + 2;
    int c = q.front() + 3;
    if (a < 11) q.push(a);
    if (b < 11) q.push(b);
    if (c < 11) q.push(c);
    q.pop();
  }
  for (int i : k) {
    cout << count[i] << '\n';
  }
  return 0;
}
