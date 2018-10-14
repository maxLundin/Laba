//
// Created by max on 12.10.2018.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<uint32_t, uint32_t>> mas[300001];
int used[300001];
int used1[300001];
int timein[300001];
int up[300001];
uint32_t time1 = 0;
int komponenta[200001];
int kolkomp = 0;

void doit(int n, int predok) {
    used1[n] = 1;
    for (int i = 0; i < mas[n].size(); i++) {
        if (!used1[mas[n][i].first]) {
            if (up[mas[n][i].first] >= timein[n]) {
                kolkomp++;
                komponenta[mas[n][i].second] = kolkomp;
                doit(mas[n][i].first, kolkomp);
            } else {
                komponenta[mas[n][i].second] = predok;
                doit(mas[n][i].first, predok);
            }
        } else {
            if (komponenta[mas[n][i].second] == 0) {
                komponenta[mas[n][i].second] = predok;
            }
        }
    }
}


void dfs(int n, int predok = -1) {
    used[n] = 1;
    timein[n] = ++time1;
    up[n] = time1;
    for (int i = 0; i < mas[n].size(); i++) {
        if (mas[n][i].second == predok) {
            continue;
        }
        if (used[mas[n][i].first]) {
            up[n] = min(up[n], timein[mas[n][i].first]);
        } else {
            dfs(mas[n][i].first, mas[n][i].second);
            up[n] = min(up[n], up[mas[n][i].first]);
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    uint32_t a1, a2;
    for (int i = 0; i < m; i++) {
        cin >> a1 >> a2;
        mas[a1].emplace_back(a2, i + 1);
        mas[a2].emplace_back(a1, i + 1);
    }

    for (int i = 1; i <= n; i++) {
        if (used[i] != 1) {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (used1[i] != 1) {
            doit(i, kolkomp);
        }
    }

    int min = komponenta[1];
    for (int i = 1; i < m; i++) {
        if (komponenta[i] < min) {
            min = komponenta[i];
        }
    }
    min -= 1;
    cout << kolkomp - min << "\n";
    for (int i = 1; i <= m; i++) {
        cout << komponenta[i] - min << " ";
    }

    return 0;
}