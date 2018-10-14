//
// Created by max on 14.10.2018.
//


#include <iostream>
#include <vector>

using namespace std;

vector<uint32_t> mas[100000];
vector<uint32_t> mas1[100000];
int used[100000];
int used1[100000];
vector<uint32_t> ans;
uint32_t res[100000];
int k;
bool massiv[10001][10001];

void dfs(uint32_t n) {
    if (used[n] == 1) {
        return;
    }
    used[n] = 1;
    for (int i = 0; i < mas[n].size(); i++) {
        dfs(mas[n][i]);
    }
    ans.push_back(n);
}

void dfs1(uint32_t n) {
    if (used1[n] == 2) {
        return;
    }
    used1[n] = 2;
    for (int i = 0; i < mas1[n].size(); i++) {
        dfs1(mas1[n][i]);
    }
    res[n] = k;

}

int main() {
    int n, m;

    std::cin >> n >> m;

    uint32_t a1, a2;
    for (int i = 0; i < m; i++) {
        cin >> a1 >> a2;
        mas[a1].push_back(a2);
        mas1[a2].push_back(a1);
    }

    for (int i = 1; i <= n; i++) {
        if (used[i] != 1) {
            dfs(i);
        }
    }
    k = 0;
    for (int i = ans.size() - 1; i >= 0; i--) {
        if (used1[ans[i]] != 2) {
            k++;
            dfs1(ans[i]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < mas[i].size(); j++) {
            massiv[res[i]][res[mas[i][j]]] = true;
        }
    }
    int g = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            if (massiv[i][j] && i != j) {
                g++;
            }
        }
    }

    cout << g;

    return 0;
}