//
// Created by max on 05.11.2018.
//

#include "bits/stdc++.h"

using namespace std;

bool mas[4000][4000];

int massiv[1001];

int main() {
    ios_base::sync_with_stdio(false);
    freopen("guyaury.in", "r", stdin);
    freopen("guyaury.out", "w", stdout);
    int n;
    cin >> n;

    char c;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cin >> c;
            mas[i+1][j+1] = (c == '1');
            mas[j+1][i+1] = !mas[i+1][j+1];
        }
    }

    for (int l = 0; l < n; l++) {
        massiv[l] = l + 1;
    }

    while (true) {
        std::random_shuffle(massiv, massiv + n);
        std::sort(massiv, massiv + n, [](int a, int b) {
            return mas[a][b];
        });
        if (mas[massiv[n-1]][massiv[0]]) {
            break;
        }
    }
   // reverse(massiv, massiv + n);
    for (int k = 0; k < n; ++k) {
        cout << massiv[k] << " ";
    }


    return 0;
}