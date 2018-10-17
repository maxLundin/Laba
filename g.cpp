//
// Created by max on 17.10.2018.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

vector<string> names(1001);
std::map<string, uint32_t> map1;

vector<uint32_t> mas[2001];
vector<uint32_t> mas1[2001];
vector<bool> used(2001);
vector<uint32_t> stack;
uint32_t component[2001];
uint32_t comp = 0;

void dfs1(int v) {
    if (used[v]) {
        return;
    }
    used[v] = true;
    for (int i = 0; i < mas[v].size(); i++) {
        dfs1(mas[v][i]);
    }
    stack.push_back(v);
}

void dfs2(int v) {
    if (used[v]) {
        return;
    }
    used[v] = true;
    component[v] = comp;
    for (int i = 0; i < mas1[v].size(); i++) {
        dfs2(mas1[v][i]);
    }
}


int main() {
    int m, n;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> names[i];
        map1.emplace(std::make_pair(names[i], 2 * i));
    }

    for (int i = 0; i < m; i++) {
        string parse;
        cin >> parse;
        bool flag1 = (parse[0] == '+');
        uint32_t number1 = map1[parse.substr(1, parse.size())];

        cin >> parse;
        cin >> parse;

        bool flag2 = (parse[0] == '+');
        uint32_t number2 = map1[parse.substr(1, parse.size())];
        cout << flag1 << number1 << flag2 << number2 << '\n';

        mas[number1 + flag1].push_back(number2 + flag2);
        mas1[number2 + flag2].push_back(number1 + flag1);
    }


    for (int i = 0; i < 2 * n; i++) {
        if (!used[i]) {
            dfs1(i);
        }
    }

    used.assign(2 * n, false);

    for (int i = stack.size() - 1; i >= 0; i--) {
        if (!used[i]) {
            ++comp;
            dfs2(i);
        }
    }

    for (int i = 0; i < n; i++) {
        if (component[i] == component[i + 1]) {
            cout << -1;
            exit(0);
        }
    }


}
