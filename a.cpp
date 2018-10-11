//
// Created by max on 11.10.2018.
//


#include <iostream>
#include <vector>

using namespace std;

vector<uint32_t> mas[100000];
int used[100000];
vector<uint32_t> ans;

void dfs(uint32_t n) {
    if (used[n]==2) {
        return;
    }
    if (used[n]==1){
        cout << -1;
        exit(0);
    }
    used[n] = 1;
    for (int i = 0; i < mas[n].size(); i++) {
        dfs(mas[n][i]);
    }
    used[n] = 2;
    ans.push_back(n);
}

int main() {
    int n, m;

    std::cin >> n >> m;

    uint32_t a1, a2;
    for (int i = 0; i < m; i++) {
        cin >> a1 >> a2;
        mas[a1].push_back(a2);
    }

    for (int i = 1; i <= n; i++) {
        if (used[i]!=2) {
            dfs(i);
        }
    }
    for (int i = n-1; i >= 0; i--) {
        cout << ans[i] << " ";
    }

    return 0;
}