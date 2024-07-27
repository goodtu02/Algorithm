#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
    fast_io;
    int h, w;
    cin >> h >> w;
    cout << (double) min(h, w) / 2 * 100;

    return 0;
}
