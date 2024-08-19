#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
    fast_io;
    int n;
    cin >> n;
    set<string> s;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        if (x != "ENTER") {
            s.insert(x);
        } else {
            answer += s.size();
            s.clear();
        }
    }
    answer += s.size();
    cout << answer;

    return 0;
}
