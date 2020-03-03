//Main idea: dp
#include <iostream>
#include <cstring>

using namespace std;

int cache[100][100];
int game[100][100];
int N;

int run(int x, int y) {
    if (x >= N || y >= N)//base case
        return 0;
    if (x == N-1 && y == N-1)
        return 1;
    int& ret = cache[x][y];
    if (ret != -1)
        return ret;
    int move = game[x][y];
    return ret = (run(x + move, y) || run(x, y + move));//이런식으로도 표현할 수 있음!
}


void input() {//입력
    int tmp;
    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> tmp;
            game[x][y] = tmp;
        }
    }
}

void JumpGame(){
    input();
    if (run(0, 0))
        cout << "YES\n";
    else
        cout << "NO\n";
}


void init() {
    memset(cache, -1, sizeof(cache));
    memset(game, -1, sizeof(game));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        init();
        JumpGame();
    }
}
