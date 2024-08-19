#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
    fast_io;
    int n, m;
    cin >> n >> m;
    set<int> a;
    set<int> b;
    vector<int> answer;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b.insert(x);
    }
    for (auto i: a) {
        if (b.find(i) == b.end()) answer.push_back(i);
    }
    if (answer.empty()) cout << 0;
    else {
        sort(answer.begin(), answer.end());
        cout << answer.size() << '\n';
        for (int i: answer) cout << i << ' ';
    }

    return 0;
}
