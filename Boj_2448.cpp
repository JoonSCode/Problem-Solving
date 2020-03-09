//Main idea: 1. 규칙 찾기 2.배열의 범위 
#include <iostream>

using namespace std;

char arr[4000][7000];

void print(int i, int j, int num) {
    if (num == 3) {
        arr[i][j + 2] = '*';
        arr[i + 1][j + 1] = '*';
        arr[i + 1][j + 3] = '*';
        for (int a = 0; a < 5; a++)
            arr[i + 2][j + a] = '*';
        return;
    }
    print(i, j + num / 2, num / 2);
    print(i + num / 2, j, num / 2);
    print(i + num / 2, j +num, num / 2);
}

void Star() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int n = 0; n < 1 + 2 * (N - 1); n++) {
            arr[i][n] = ' ';
        }
    }
    print(0,0,N);
    for (int i = 0; i < N; i++) {
        for (int n = 0; n < 1 + 2 * (N - 1); n++) {
            cout<<arr[i][n];
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Star();
}
