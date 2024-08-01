#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
#define int long long
    fast_io;
    int n, k;
    cin >> n;
    vector<int> list;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        list.push_back(a);
    }
    cin >> k;
    int count = 0;
    for (auto left = list.begin(); left != list.end(); ++left) {
        long long sum = *left;
        auto right = left + 1;
        if (sum > k) {
            count += (list.end() - left);
            continue;
        }
        while (right != list.end()) {
            sum += *right;
            if (sum > k) {
                count += (list.end() - right);
                break;
            }
            ++right;
        }
    }
    cout << count;
    return 0;
}
