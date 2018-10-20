//
// Created by max on 20.10.2018.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;


int mas[1000][1000];
vector<bool> used(1000);
int m = 0, n;

void dfs1(int v) {
    used[v] = true;
    for (int i = 0; i < n; i++) {
        if (mas[v][i] <= m && !used[i]) {
            dfs1(i);
        }
    }
}

void dfs2(int v) {
    used[v] = true;
    for (int i = 0; i < n; i++) {
        if (mas[i][v] <= m && !used[i]) {
            dfs2(i);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);

    std::freopen("avia.in", "r", stdin);
    std::freopen("avia.out", "w", stdout);

    cin >> n;
    uint32_t max = 0;
    uint32_t ch;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ch;
            if (ch > max) {
                max = ch;
            }
            mas[i][j] = ch;
        }
    }
    int l, r;

    l = -1;
    r = max;

    label:
    while (r - l > 1) {
        used.assign(n, false);
        m = ((l + r) / 2);
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                if (i != 0) {
                    l = m;
                    goto label;
                }
                dfs1(i);
            }
        }
        used.assign(n, false);

        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                if (i != 0) {
                    l = m;
                    goto label;
                }
                dfs2(i);
            }
        }
        r = m;
    }

    std::cout << r << std::endl;


}
close