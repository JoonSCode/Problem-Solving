//Main idea: 1.규칙 찾기 2. 문제 
#include <iostream>

using namespace std;

char arr[2187][2187];

void print(int i, int j, int num) {//사각형의 가운데 num/3만큼만 공백이다.
    if (num == 3) {
        arr[i + 1][j + 1] = ' ';
        return;
    }
    print(i, j, num / 3);
    print(i, j + num / 3, num / 3);
    print(i, j + 2 * num / 3, num / 3);
    print(i + num / 3, j, num / 3);
    print(i + num / 3, j + 2 * num / 3, num / 3);
    print(i + 2 * num / 3, j, num / 3);
    print(i + 2 * num / 3, j + num / 3, num / 3);
    print(i + 2 * num / 3, j + 2 * num / 3, num / 3);

    int a = i + num / 3;
    int b = j + num / 3;
    for (int n = 0; n < num / 3; n++) {
        for (int k = 0; k < num / 3; k++) {
            arr[a + n][b + k] = ' ';
        }
    }
}

void Star() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int n = 0; n < N; n++) {
            arr[i][n] = '*';
        }
    }
    print(0,0,N);
    for (int i = 0; i < N; i++) {
        for (int n = 0; n < N; n++) {
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
