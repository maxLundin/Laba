//
// Created by max on 04.11.2018.
//

#include "bits/stdc++.h"

using namespace std;


int mas[100][100];
int mas1[100][100];

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mas[i][j];
            mas1[i][j] = mas[i][j];
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                mas1[j][k] = min(mas1[j][k], mas1[j][i] + mas1[i][k]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mas1[i][j] << " ";
        }
        cout << "\n";
    }

}