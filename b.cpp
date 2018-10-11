//
// Created by max on 11.10.2018.
//

#include <iostream>
#include <vector>

using namespace std;

vector<uint32_t> mas[100000];


int main() {
    int n, m;

    std::cin >> n >> m;

    uint32_t a1, a2;
    for (int i = 0; i < m; i++) {
        cin >> a1 >> a2;
        mas[a1].push_back(a2);
    }



    return 0;
}