//
// Created by max on 11.11.2018.
//


#include "bits/stdc++.h"

using namespace std;

struct tri {
    int a;
    int b;
    int64_t cost;
};

const int64_t maximum = (long long) 2e18 + 10;

int64_t mas[10000];
int64_t path[10000];
tri massiv[10000];
bool inf[10000];

vector<pair<int, long long>> mass[2001];
bool used[3000];

void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < mass[v].size(); i++) {
        if (!used[mass[v][i].first]) {
            dfs(mass[v][i].first);
        }
    }
}

void dfs1(int v) {
    inf[v] = true;
    for (int i = 0; i < mass[v].size(); i++) {
        if (!inf[mass[v][i].first]) {
            dfs1(mass[v][i].first);
        }
    }
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    int pos = 0;
    for (int i = 0; i < 10000; i++) {
        mas[i] = INT64_MAX;
    }

    int64_t t;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> t;
        massiv[pos].a = a;
        massiv[pos].b = b;
        massiv[pos++].cost = t;
        mass[a].emplace_back(b, t);
    }

    dfs(s);


    mas[s] = 0;
    int temp = -1;
    for (int i = 1; i <= n; i++) {
        if (i == n) {
            for (int j = 0; j < pos; j++) {
                if (mas[massiv[j].a] != INT64_MAX)
                    if (mas[massiv[j].b] > mas[massiv[j].a] + massiv[j].cost) {
                        mas[massiv[j].b] = mas[massiv[j].a] + massiv[j].cost;
                        path[massiv[j].b] = massiv[j].a;
                        inf[massiv[j].b] = true;
                        temp = massiv[j].b;
                    }
            }
        } else {
            for (int j = 0; j < pos; j++) {
                if (mas[massiv[j].a] != INT64_MAX)
                    if (mas[massiv[j].b] > mas[massiv[j].a] + massiv[j].cost) {
                        mas[massiv[j].b] = mas[massiv[j].a] + massiv[j].cost;
                        path[massiv[j].b] = massiv[j].a;
                    }
            }
        }
    }


    for (int i = 1; i <= n; i++) {
        if (inf[i]) {
            dfs1(i);
            int temp = i;
            for (int j = 0; j < n; j++) {
                temp = path[temp];
            }
            dfs1(temp);
        }
    }


    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            cout << "*\n";
        } else if (inf[i]) {
            cout << "-\n";
        } else {
            cout << mas[i] << "\n";
        }
    }
}
