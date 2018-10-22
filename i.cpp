//
// Created by max on 22.10.2018.
//

#include <iostream>
#include <cmath>
#include <set>
#include <bitset>
#include <algorithm>
#include <vector>

using namespace std;

std::pair<int64_t, int64_t> mas[10000];


int64_t len1(int i, int j) {
    auto k1 = mas[i];
    auto k2 = mas[j];
    return ((k1.first - k2.first) * (k1.first - k2.first) +
            (k2.second - k1.second) * (k2.second - k1.second));
}


int parent[10000];
int rank1[10000];

int64_t key[10000];


void make_set(int v) {
    parent[v] = v;
    rank1[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank1[a] < rank1[b])
            swap(a, b);
        parent[b] = a;
        if (rank1[a] == rank1[b])
            ++rank1[a];
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    uint32_t n;
    cin >> n;
    vector<int> Qu;
    for (int i = 0; i < n; i++) {
        cin >> mas[i].first >> mas[i].second;
//        make_set(i);
        Qu.push_back(i);
    }

    double sumT = 0;

    for (int i = 0; i < n; i++) {
        key[i] = INT64_MAX;
    }

    key[0] = 0;

    while (!Qu.empty()) {
        long long min = key[Qu[0]];
        int nom = 0;
        for (int i = 0; i < Qu.size(); i++) {
            if (min > key[Qu[i]]) {
                min = key[Qu[i]];
                nom = i;
            }
        }

        int h = Qu[nom];

        Qu.erase(Qu.begin() + nom);

        for (int i : Qu) {
            if (key[i] > len1(h, i)) {
                key[i] = len1(h, i);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        sumT += sqrt(key[i]);
    }

    cout << sumT;
}