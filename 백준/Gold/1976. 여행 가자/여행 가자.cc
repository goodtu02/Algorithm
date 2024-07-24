#include <bits/stdc++.h>
#define fast_io cin.tie(NULL); ios_base::sync_with_stdio(false)
using namespace std;

vector<int> city;

int find(int x) {
    if (city[x] == x) return x; // 대표 노드 반환
    return city[x] = find(city[x]); //경로 압축
}

void union_(int x, int y) {
    //대표 노드 합치기
    x = find(x);
    y = find(y);
    city[x] = min(x, y);
    city[y] = min(x, y);
}

int main() {
    fast_io;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) city.push_back(i);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            if (a == 1) union_(i, j);
        }
    }
    vector<int> schedule;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        schedule.push_back(a - 1);
    }
    for (int i = 0; i < schedule.size() - 1; i++) {
        if (find(schedule[i]) != find(schedule[i + 1])) {
            //같은 집합 확인
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
