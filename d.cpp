//
// Created by max on 12.10.2018.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<uint32_t, uint32_t>> mas[200001];
int used[200001];
int timein[200001];
int up[200001];
vector<uint32_t> ans;
uint32_t time1 = 0;
int komponenta[200001];
int kolkomp = 0;
vector<uint32_t> stack;
int temp;

void dfs(int n, int predok = -1) {
    used[n] = 1;
    stack.push_back(n);
    timein[n] = ++time1;
    up[n] = time1;
    for (int i = 0; i < mas[n].size(); i++) {
        if (mas[n][i].second == predok) {
            continue;
        }
        if (used[mas[n][i].first]) {
            up[n] = min(up[n], timein[mas[n][i].first]);
        } else {
            // predok = n;
            dfs(mas[n][i].first, mas[n][i].second);
            up[n] = min(up[n], up[mas[n][i].first]);
            if (up[mas[n][i].first] > timein[n]) {
                //ans.push_back(mas[n][i].second);
                while ((temp = stack.back()) != (mas[n][i].first)) {
                    stack.pop_back();
                    komponenta[temp] = kolkomp;
                }
                stack.pop_back();
                komponenta[temp] = kolkomp;
                kolkomp++;
            }
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
        stack.clear();
        if (used[i] != 1) {
            kolkomp++;
            dfs(i);
            while (!stack.empty()) {
                temp = stack.back();
                stack.pop_back();
                komponenta[temp] = kolkomp;
            }
        }
    }


    cout << kolkomp << "\n";
    for (int i = 1; i <= n; i++) {
        cout << komponenta[i] << " ";
    }


    return 0;
}