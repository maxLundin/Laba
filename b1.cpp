//
// Created by max on 04.11.2018.
//

#include "bits/stdc++.h"

using namespace std;

uint32_t mas1[30002];
bool used[30002];
vector<pair<uint32_t, uint32_t>> mas[30002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n + 1; i++) {
        mas1[i] = INT32_MAX;
        mas[i].reserve(1000);
    }
    uint32_t a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        mas[a].emplace_back(b, c);
        mas[b].emplace_back(a, c);
    }

    mas1[1] = 0;
    set<pair<int, int>> queue;
    used[1] = true;
    for (auto &i : mas[1]) {
        mas1[i.first] = i.second;
        queue.insert({mas1[i.first], i.first});
    }
    int v;
    while(!queue.empty()) {

        do {
            v = (*queue.begin()).second;
            queue.erase(queue.begin());
        } while (used[v] && !queue.empty());

        used[v] = true;
        for (int j = 0; j < mas[v].size(); ++j) {
            if (mas1[v] + mas[v][j].second < mas1[mas[v][j].first]) {
                mas1[mas[v][j].first] = mas1[v] + mas[v][j].second;
                queue.insert({mas1[mas[v][j].first], mas[v][j].first});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << mas1[i] << " ";
    }

}
