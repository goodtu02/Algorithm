#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
    fast_io;
    while(true)
    {
        int a,b;
        cin>>a>>b;
        if(a==b&&a==0) break;
        if(a>b) cout<<"Yes"<<'\n';
        else cout<<"No"<<'\n';
    }
    return 0;
}
