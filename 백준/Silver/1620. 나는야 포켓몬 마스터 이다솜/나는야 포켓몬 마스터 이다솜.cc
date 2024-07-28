#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

int main() {
    fast_io;
    int n, m;
    cin >> n >> m;
    map<string, int> pokemon;
    vector<string> pokemons;
    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        pokemon.insert({str, i});
        pokemons.push_back(str);
    }
    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;
        if (isdigit(str[0])) cout << pokemons[stoi(str) - 1] << '\n';
        else {
            auto target = pokemon.find(str);
            cout << target->second << '\n';
        }
    }
    return 0;
}
