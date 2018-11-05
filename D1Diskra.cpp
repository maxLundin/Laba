//
// Created by max on 05.11.2018.
//

#include ""

int main(){
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

    return 0;
}