//
// Created by max on 04.11.2018.
//

#include "bits/stdc++.h"

using namespace std;


uint32_t mas1[30000][30000];

int main() {

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mas1[i][j] = INT32_MAX;
        }
    }
    uint32_t a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        mas1[a][b] = c;
        mas1[b][a] = c;
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                mas1[j][k] = min(mas1[j][k], mas1[j][i] + mas1[i][k]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        uint32_t min = UINT32_MAX;
        for (int j = 0; j < n; j++) {
            if (mas1[i][j] < min) {
                min = mas1[i][j];
            }
        }
        cout << min << " ";
    }

}
