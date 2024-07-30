#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
    fast_io;
    vector<int> list;
    int n = -1;
    while (n != 0) {
        cin >> n;
        list.push_back(n);
    }
    int m = *max_element(list.begin(), list.end());
    vector<int> sieve(m + 1); //에라토스테네스의 체
    for (int i = 0; i < sieve.size(); i++) sieve[i] = i;
    sieve[1] = 0;
    for (int i = 2; i <= sqrt(m); i++) {
        if (sieve[i] == 0) continue;
        for (int j = i * i; j <= m; j += i) sieve[j] = 0;
    }
    for (int i: list) {
        if (i == 0) break;
        auto left = sieve.begin();
        auto right = left + i;
        bool pos = false;
        while (true) {
            while (*left == 0) ++left;
            while (*right == 0) --right;
            if (*left + *right == i) {
                cout << i << " = " << *left << " + " << *right << '\n';
                pos = true;
                break;
            }
            if (*left + *right > i) --right;
            else if (*left + *right < i) ++left;
        }
        if(!pos) cout << "Goldbach's conjecture is wrong." << '\n';
    }
    return 0;
}
