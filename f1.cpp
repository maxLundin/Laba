//
// Created by max on 15.11.2018.
//

#include "bits/stdc++.h"

using namespace std;

uint64_t mas1[100002];
bool used1[100002];
uint64_t mas2[100002];
bool used2[100002];
vector<pair<uint64_t, uint64_t>> mas[100002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n + 1; i++) {
        mas1[i] = INT64_MAX;
        mas2[i] = INT64_MAX;
        //mas[i].reserve(1000);
    }
    uint64_t a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        mas[a].emplace_back(b, c);
        mas[b].emplace_back(a, c);
    }

    cin >> a >> b >> c;

    mas1[a] = 0;
    set<int> queue;
    used1[a] = true;
    for (auto &i : mas[a]) {
        mas1[i.first] = i.second;
        queue.insert(i.first);
    }
    int v;
    while (!queue.empty()) {

        v = (*queue.begin());
        queue.erase(queue.begin());


        used1[v] = true;
        for (int j = 0; j < mas[v].size(); ++j) {
            if (mas1[v] + mas[v][j].second < mas1[mas[v][j].first]) {
                mas1[mas[v][j].first] = mas1[v] + mas[v][j].second;
                queue.insert(mas[v][j].first);
            }
        }
    }


    mas2[b] = 0;
    set<int> queue2;
    used2[b] = true;
    for (auto &i : mas[b]) {
        mas2[i.first] = i.second;
        queue2.insert(i.first);
    }
    int v2;
    while (!queue2.empty()) {

        v2 = (*queue2.begin());
        queue2.erase(queue2.begin());

        used2[v2] = true;
        for (int j = 0; j < mas[v2].size(); ++j) {
            if (mas2[v2] + mas[v2][j].second < mas2[mas[v2][j].first]) {
                mas2[mas[v2][j].first] = mas2[v2] + mas[v2][j].second;
                queue2.insert(mas[v2][j].first);
            }
        }
    }

    int64_t ab = mas1[b];
    int64_t ac = mas1[c];
    int64_t bc = mas2[c];


//    if (mas1[b] != mas2[a]) {
//        throw runtime_error("wooh");
//    }

    //    if (ab+ac <= ab+bc && ab+ac <= ac+bc){
    //            if (ab+ac <)
    //    }

    if ((ab == INT64_MAX && (bc == INT64_MAX || ac == INT64_MAX)) || (bc == INT64_MAX && ac == INT64_MAX)) {
        cout << -1;
        exit(0);
    }

    cout << min(min(ab + ac, ab + bc), ac + bc)
         << std::endl;


    //    for (int i = 1; i <= n; ++i) {
    //        cout << mas1[i] << " ";
    //    }


}
