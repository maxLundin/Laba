//
// Created by max on 11.10.2018.
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
vector<uint32_t> ans;
vector<uint32_t> ans1;
uint32_t time1 = 0;


void dfs(int n, int predok = -1) {
    used[n] = 1;
    timein[n] = ++time1;
    up[n] = time1;
    int visited = 0;
    for (int i = 0; i < mas[n].size(); i++) {
        if (mas[n][i].first == predok) {
            continue;
        }
        if (used[mas[n][i].first]) {
            up[n] = min(up[n], timein[mas[n][i].first]);
        } else {
            // predok = n;
            dfs(mas[n][i].first, n);
            visited++;
            up[n] = min(up[n], up[mas[n][i].first]);
            if (up[mas[n][i].first] >= timein[n] && predok != -1) {
                ans.push_back(n);
            }
        }
    }
    if (predok == -1 && visited > 1) {
        ans.push_back(n);
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


    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        if (ans1.size()==0 || ans1.back() != ans[i])
            ans1.push_back(ans[i]);
    }
    cout << ans1.size() << "\n";
    for (int i = 0; i < ans1.size(); i++) {
        cout << ans1[i] << " ";
    }

    return 0;
}