#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
    fast_io;
    int n;
    cin >> n;
    queue<pair<int, int>> q;
    q.push(make_pair(n, 0));
    while (!q.empty()) {
        auto k = q.front();
        if (k.first % 3 == 0) {
            q.push(make_pair(k.first / 3, k.second + 1));
            if (k.first / 3 == 1) break;
        }
        if (k.first % 2 == 0) {
            q.push(make_pair(k.first / 2, k.second + 1));
            if (k.first / 2 == 1) break;
        }
        if (k.first > 3) q.push(make_pair(k.first - 1, k.second + 1));
        if (q.back().first == 1) break;
        q.pop();
    }
    cout << q.back().second;
    return 0;
}
