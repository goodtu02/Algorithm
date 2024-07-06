#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  string exp;
  cin >> exp;
  int sum = 0, plus = 0;
  bool bracket = true; //괄호 닫힘 확인
  for (int i = 0; i < exp.size(); i++) {
	if (exp[i] == '-' && bracket) {
	  exp.insert(i + 1, "(");
	  bracket = false;
	} else if (exp[i] == '-' && !bracket) {
	  exp.insert(i, ")");
	  bracket = true;
	}
  }
  if (!bracket) exp.append(")");
  string num = " ";
  bracket = true;
  for (char& i : exp) {
	if (!bracket) { //괄호 안의 수 더하기
	  if (isdigit(i)) num += i;
	  else if (i == '+' || i == ')') {
		plus += stoi(num);
		num = " ";
	  }
	}
	if (i == '(') bracket = false;
	if (i == ')') {
	  bracket = true;
	  sum -= plus;
	  plus = 0;
	}
	if (bracket && isdigit(i)) num += i; //괄호 밖 수 더하기
	else if (bracket) {
	  if (num != " ") sum += stoi(num);
	  num = " ";
	}
  }
  if (num != " ") sum += stoi(num);
  cout << sum;
  return 0;
}