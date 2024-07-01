#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
  fast_io;
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
	for(int j=0;j<n-(i+1);j++) cout<<' ';
	for(int k=0;k<2*i+1;k++) cout<<'*';
	cout<<'\n';
  }
  return 0;
}