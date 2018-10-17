//
// Created by max on 17.10.2018.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

string name;
std::map<string, uint32_t> map1;
std::map<uint32_t, string> map2;

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
        cin >> name;
        map1.emplace(std::make_pair(name, 2 * i));
        map2.emplace(std::make_pair(2 * i, name));
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
        //cout << flag1 << number1 << flag2 << number2 << '\n';

        mas[number1 + flag1].push_back(number2 + flag2);
        mas[number2 + !flag2].push_back(number1 + !flag1);
        mas1[number2 + flag2].push_back(number1 + flag1);
        mas1[number1 + !flag1].push_back(number2 + !flag2);
    }


    for (int i = 0; i < 2 * n; i++) {
        if (!used[i]) {
            dfs1(i);
        }
    }

    used.assign(2 * n, false);

    for (int i = stack.size() - 1; i >= 0; i--) {
        if (!used[stack[i]]) {
            ++comp;
            dfs2(stack[i]);
        }
    }

    for (int i = 0; i < n; i += 2) {
        if (component[i] == component[i + 1]) {
            cout << -1;
            exit(0);
        }
    }

    vector<string> buf;
    uint32_t count = 0;
    for (int i = 0; i < 2 * n; i += 2) {
        if (component[i] < component[i + 1]) {
            count++;
            buf.emplace_back(map2[i]);
        }
    }

    if (count == 0) {
        throw runtime_error("hhh");
    }

    cout << count << endl;
    for (int i = 0; i < buf.size(); i++) {
        cout << buf[i] << '\n';
    }


}
