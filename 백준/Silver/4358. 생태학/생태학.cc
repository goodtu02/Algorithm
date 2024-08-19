#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
    fast_io;
    map<string, int> tree;
    int count = 0;
    string s;
    while (getline(cin, s)) {
        count++;
        if (tree.find(s) != tree.end()) tree[s] += 1;
        else tree.insert(make_pair(s, 1));
    }
    for (auto i: tree) {
        double answer = (double) i.second * 100 / count;
        cout << fixed;
        cout.precision(4);
        cout << i.first << ' ' << answer << '\n';
    }
    return 0;
}
