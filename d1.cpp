//
// Created by max on 09.11.2018.
//


#include "bits/stdc++.h"

using namespace std;


struct tri {
    int a;
    int b;
    int cost;
};

vector<int> mas(10010);
vector<int> mascurrent(10010);
int path[10010];
bool used[10010];
bool used1[10010];
tri massiv[10010];

int main() {
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    int pos = 0;
    for (int i = 0; i < 10010; i++) {
        mas[i] = INT32_MAX >> 3;
        mascurrent[i] = INT32_MAX >> 3;
    }

    int a, b, t;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> t;
        massiv[i].a = a;
        massiv[i].b = b;
        massiv[i].cost = t;
    }

    int ans = INT32_MIN;
    mas[s] = 0;
    used[s] = true;
//    mas1[s] = 0;
    int temp = -1;
    for (int i = 1; i <= k; i++) {
        fill(used, used + 10010, false);
        fill(mascurrent.data(), mascurrent.data() + 10010, INT32_MAX >> 3);

        for (int j = 0; j < m; j++) {
            if (mas[massiv[j].a] != INT32_MAX >> 3) {
                if (mascurrent[massiv[j].b] > mas[massiv[j].a] + massiv[j].cost) {
                    mascurrent[massiv[j].b] = mas[massiv[j].a] + massiv[j].cost;
                    used[massiv[j].b] = true;
                }

            }
        }
        for (int h = 1; h <= n; h++) {
            if (!used[h]) {
                mascurrent[h] = INT32_MAX >> 3;
            }
        }
        swap(mas, mascurrent);
    }


    for (int i = 1; i <= n; i++) {
        if (used[i]) {
            cout << mas[i] << "\n";
        } else {
            cout << "-1\n";
        }
    }


}
