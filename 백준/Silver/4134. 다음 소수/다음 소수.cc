#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

bool decimal(long long n) {
    for (long long i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    fast_io;
    int t;
    cin >> t;
    vector<int> list;
    for (int i = 0; i < t; i++) {
        long long n;
        cin >> n;
        long long k = n;
        while (true) {
            if (k == 0 || k == 1) {
                cout << 2 << '\n';
                break;
            }
            if (decimal(k)) {
                cout << k << '\n';
                break;
            }
            k++;
        }
    }
    return 0;
}
