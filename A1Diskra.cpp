//
// Created by max on 02.11.2018.
//


#include <bits/stdc++.h>

using namespace std;

bool mas[4000][4000];

int main() {
    ios_base::sync_with_stdio(false);
    freopen("fullham.in", "r", stdin);
    freopen("fullham.out", "w", stdout);

    int n;
    cin >> n;

    char c;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cin >> c;
            mas[i][j] = (c == '1');
            mas[j][i] = mas[i][j];
        }
    }


    deque<int> queue;
    for (int i = 0; i < n; i++) {
        queue.push_back(i);
    }
    int i = 0;
    for (int k = 0; k < n * (n - 1); k++) {
        if (!mas[queue[0]][queue[1]]) {
            i = 2;
            while (!mas[queue[0]][queue[i]] || !mas[queue[1]][queue[i + 1]]) {
                i++;
            }

//            std::cout << "i: "<< i <<std::endl;
            reverse(queue.begin() + 1, queue.begin() + i + 1);
//            random_shuffle(queue.begin()+1, queue.begin()+i);
        }
        queue.push_back(queue[0]);
//        queue.erase(queue.begin());
        queue.pop_front();
    }

    for (int i : queue) {
        cout << i + 1 << " ";
    }

}

