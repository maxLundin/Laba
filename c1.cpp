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

int mas[10000];
int path[10000];
tri massiv[10000];

int main() {
    int n;
    cin >> n;
    int pos = 0;
    for (int i = 0; i < 10000; i++) {
        mas[i] = INT32_MAX >> 3;
    }

    int t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> t;
            if (t != 100000) {
                massiv[pos].a = i;
                massiv[pos].b = j;
                massiv[pos++].cost = t;
            }
        }
    }

    int ans = INT32_MIN;
    int ans1 = 0;
    int way = 0;
    mas[0] = 0;
    int temp = -1;
    for (int i = 1; i <= n; i++) {
        temp = -1;
        for (int j = 0; j < pos; j++) {
            if (mas[massiv[j].b] > mas[massiv[j].a] + massiv[j].cost) {
                mas[massiv[j].b] = mas[massiv[j].a] + massiv[j].cost;
                path[massiv[j].b] = massiv[j].a;
                temp = massiv[j].b;
            }
        }
    }


    if (temp != -1) {
        int v = temp;
        vector<int> ansver;
        for (int i = 0; i < n; i++) {
            temp = path[temp];
        }
        int cur = temp;
        while (temp != cur || ansver.size() <= 1) {
            temp = path[temp];
            ansver.push_back(temp);
        }

        cout << "YES" << endl;

        reverse(ansver.begin(), ansver.end());
        cout << ansver.size() << endl;
        for (int i = 0; i < ansver.size(); i++) {
            cout << ansver[i] + 1 << " ";
        }

    } else {
        cout << "NO";
    }


}
