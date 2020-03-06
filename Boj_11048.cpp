//Main idea: 맨 위 맨 왼쪽 선처리 후에 하면 규칙 일정
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
int maze[1000][1000];

void input() {
    memset(maze, -1, sizeof(maze));
    cin >> N >> M;
    int tmp;
    for (int i = 0; i < N; i++) {
        for (int n = 0; n < M; n++) {
            cin >> tmp;
            maze[i][n] = tmp;
        }
    }
}
void Move(){
    input();
    for (int i = 1; i < M; i++) //가로 맨 윗줄 선처리
        maze[0][i] += maze[0][i - 1];
    for (int i = 1; i < N; i++) //세로 맨 왼쪽 줄 선처리
        maze[i][0] += maze[i-1][0];

    for (int r = 1; r < N; r++) {
        for (int c = 1; c < M; c++) 
            maze[r][c] += max(maze[r - 1][c - 1], max(maze[r - 1][c], maze[r][c - 1]));
    }
    cout << maze[N - 1][M - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Move();
}
