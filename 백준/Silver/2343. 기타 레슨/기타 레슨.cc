#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

static vector<int> list;
static int target;
int blueray(int size) //블루레이 개수 확인
{
  int count = 1;
  int sum = 0;
  for (int& i : list) {
	sum += i;
	if (sum == size) {
	  sum = 0;
	  count++;
	} else if (sum > size) {
	  sum = i;
	  count++;
	}
  }
  if (sum == 0) count--;
  return count;
}
int binary_search(int start, int end) {
  int mid = (start + end) / 2;
  if (start > end) return start; //타겟보다 작은 블루레이 개수 가능
  if (blueray(mid) < target) return binary_search(start, mid - 1);
  else if (blueray(mid) > target) return binary_search(mid + 1, end);
  else return mid;
}
int main() {
  fast_io;
  int n, m, sum = 0;
  cin >> n >> m;
  target = m;
  for (int i = 0; i < n; i++) {
	int a;
	cin >> a;
	list.push_back(a);
	sum += a;
  }
  int min = *max_element(list.begin(), list.end());
  auto result = binary_search(min, sum);
  while (true) { //최소값 검사
	if (result == min) break;
	if (blueray(result - 1) > target) break;
	result--;
  }
  cout << result;
  return 0;
}