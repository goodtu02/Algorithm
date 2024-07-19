#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
#define long long long
using namespace std;

static vector<long> august14;
static vector<vector<pair<long, pair<long, long>>>> august;
static vector<bool> visited;
static long lcm = 1;

long gcd(long x, long y) {
  long r = x % y;
  if (r == 0) return y;
  else return gcd(y, r);
}
void dfs(long x) {
  if (!visited[x]) {
	visited[x] = true;
	for (auto& i : august[x]) {
	  if (!visited[i.first]) {
		august14[i.first] = august14[x] / i.second.first * i.second.second;
		dfs(i.first);
	  }
	}
  } else return;
}

int main() {
  fast_io;
  int n;
  cin >> n;
  august = vector<vector<pair<long, pair<long, long>>>>(n);
  august14 = vector<long>(n, 1);
  visited = vector<bool>(n, false);
  for (int i = 0; i < n - 1; i++) {
	int a, b, p, q;
	cin >> a >> b >> p >> q;
	long temp = p * q / gcd(p, q);
	lcm = lcm * temp;
	august[a].push_back(make_pair(b, make_pair(p, q)));
	august[b].push_back(make_pair(a, make_pair(q, p)));
  }
  august14[0] = lcm;
  dfs(0);
  long temp = august14[0];
  for (long i = 0; i < n; i++) temp = gcd(temp, august14[i]);
  for (long& i : august14) cout << i / temp << ' ';
  return 0;
}