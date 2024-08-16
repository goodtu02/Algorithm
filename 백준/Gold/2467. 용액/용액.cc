#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

bool sortabs(int a, int b) {
    return abs(a) < abs(b);
}

int main() {
    fast_io;
    int n;
    cin >> n;
    vector<int> liquid;
    int minnum = 2000000000;
    pair<int, int> result;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        liquid.push_back(a);
    }
    sort(liquid.begin(), liquid.end(), sortabs);
    for (int i = 0; i < n - 1; i++) {
        if (minnum > abs(liquid[i + 1] + liquid[i])) {
            minnum = abs(liquid[i + 1] + liquid[i]);
            result = make_pair(liquid[i + 1], liquid[i]);
        }
    }
    cout << min(result.first, result.second) << ' ' << max(result.first, result.second);
    return 0;
}
