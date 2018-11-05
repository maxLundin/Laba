//
// Created by max on 02.11.2018.
//


#include <bits/stdc++.h>

using namespace std;

bool mas[4000][4000];

string st;

int massiv[1001];

void merge(int *a, int size_a, const int *b, int size_b) {
    int mas[size_a + size_b];
    int pos = 0;
    int posa = 0, posb = 0;
    for (int i = 0; i < size_a + size_b; i++) {
        cout << 1 << " " << *(a + posa) << " " << *(b + posb) << endl;
        cin >> st;
        if (st[0] == 'Y') {
            mas[pos++] = *(a + posa++);
        } else {
            mas[pos++] = *(b + posb++);
        }
    }
    for (int i = 0; i < size_a + size_b; ++i) {
        *(a + i) = mas[i];
    }
}

void sort(int *a, int size) {
    if (size == 1) {
        return;
    } else {
        merge(a, size / 2, a + size / 2, size - size / 2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        massiv[i] = i + 1;
    }

    //random_shuffle(massiv, massiv + n);

    //sort(massiv, n);

    std::stable_sort(massiv, massiv + n, [](int a, int b) {
        cout << 1 << " " << a << " " << b << endl;
        cin >> st;
        return st[0] == 'Y';
    });
    cout << 0 << " ";
    for (int i = 0; i < n; i++) {
        cout << massiv[i] << " ";
    }

}

