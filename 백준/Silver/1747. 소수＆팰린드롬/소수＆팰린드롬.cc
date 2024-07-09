#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <deque>

#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  int n;
  cin >> n;
  int max = 2000000;
  vector<int> sieve(max + 1, 0); //에라토스테네스의 체
  for (int i = 2; i <= max; i++) sieve[i] = i;
  for (int j = 2; j <= sqrt(max); j++) {
	if (sieve[j] == 0) continue;
	for (int i = j * j; i < sieve.size(); i += j) {
	  if (sieve[i] % j == 0) sieve[i] = 0;
	}
  }
  for (int i = 0; i < n; i++) sieve[i] = 0;
  sort(sieve.begin(), sieve.end(), less());
  sieve.erase(remove(sieve.begin(), sieve.end(), 0), sieve.end());
  vector<string> list;
  for (int& i : sieve) list.push_back((to_string(i)));
  for (string& i : list) {
	deque<char> palindrome;
	for (char& j : i) palindrome.push_back(j);
	if (i.size() == 1) {
	  cout << i;
	  return 0;
	} else if (i.size() % 2 == 0) //길이 짝수
	{
	  for (int k = 0; k < i.size(); k++) {
		if (palindrome.front() == palindrome.back()) {
		  palindrome.pop_front();
		  palindrome.pop_back();
		} else break;
		if (palindrome.empty()) {
		  cout << i;
		  return 0;
		}
	  }
	} else { //길이 홀수
	  for (int k = 0; k < i.size(); k++) {
		if (palindrome.front() == palindrome.back()) {
		  palindrome.pop_front();
		  palindrome.pop_back();
		} else break;
		if (palindrome.size() == 1) {
		  cout << i;
		  return 0;
		}
	  }
	}
  }
  return 0;
}