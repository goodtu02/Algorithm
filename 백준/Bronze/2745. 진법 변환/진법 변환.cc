#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
    fast_io;
    string str;
    int b;
    cin >> str >> b;
    long long result = 0;
    int idx = 0;
    for (int i = str.size() - 1; i >= 0; i--) {
        int k = str[i];
        if (isalpha(k) != 0) k = str[i] - 55;
        else k = str[i] - 48;
        result += k * pow(b, idx);
        idx++;
    }
    cout << result;
    return 0;
}
