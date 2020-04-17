//Main idea: 1. 확산, 이동으로 함수 나누어서 구현하기 2. 이동에서 값이 먹히지 않도록 주의
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <utility>

using namespace std;

int R, C, T;

vector<vector<int>> tmpDirt;
vector<vector<int>> dirt;
vector<pair<int, int>> air;
pair<int, int> order[4] = { {0,1},{1,0},{-1,0},{0,-1} };

void diffusion() {
    tmpDirt.clear();
    tmpDirt.resize(R, vector<int>(C, 0));
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            if (dirt[y][x] == -1 || dirt[y][x] == 0) continue;//이동할 먼지가 없는 경우, 공기청정기인 경우
            int cnt = 0;
            for (pair<int, int>& a : order) {
                int ny = y + a.first;
                int nx = x + a.second;
                if (ny < 0 || nx < 0 || ny >= R || nx >= C || dirt[ny][nx] == -1) continue;//범위밖이거나 공기청정기인 경우
                tmpDirt[ny][nx] += dirt[y][x] / 5;
                cnt++;
            }
            dirt[y][x] -= (dirt[y][x] / 5) * cnt;
        }
    }
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++)
            dirt[y][x] += tmpDirt[y][x];
    }
}

void moveDown(int y,int x, int val) {//아래에서 위로 오는 경우
    while (y != min(R-1, val)) {
        if (dirt[y][x] != -1)
            dirt[y][x] = dirt[y+1][x];
        y++;
    }
}
void moveUp(int y, int x, int val) {//위에서 아래로 바람따라 이동하는 경우
    while (y != max(val,0)) {
        if (dirt[y][x] != -1)
            dirt[y][x] = dirt[y - 1][x];
        y--;
    }
}
void moveLeft(int y, int x) {//왼쪽에서 오른쪽으로 가는 경우
    while (x != 1) {
        if (dirt[y][x] != -1)
            dirt[y][x] = dirt[y][x - 1];
        x--;
    }
}
void moveRight(int y, int x) {//오른쪽에서 왼쪽으로 가는 경우
    while (x != C-1) {
        if (dirt[y][x] != -1)
            dirt[y][x] = dirt[y][x + 1];
        x++;
    }
}

void work() {
    for (pair<int, int>& a : air) {
        int y = a.first;
        int x = a.second;
        
        if (dirt[y - 1][x] == -1) {//y,x가 아래쪽이라는 의미
            moveDown(y, x, R);
            moveRight(R - 1, x);
            moveUp(R - 1, C - 1, y);
            moveLeft(y, C - 1);
        }
        else {
            moveUp(y, x, -1);
            moveRight(0, x);
            moveDown(0, C - 1, y);
            moveLeft(y, C - 1);
        }
        dirt[y][x + 1] = 0;
    }
}

void input() {
    cin >> R >> C >> T;
    dirt.resize(R, vector<int>(C));
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            int tmp;
            cin >> tmp;
            if (tmp == -1)
                air.push_back({ y,x });
            dirt[y][x] = tmp;
        }
    }
}

void solution() {
    input();
    while (T--) {
        diffusion();
        work();
    }

    int answer = 0;
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++)
            if (dirt[y][x] != -1) answer += dirt[y][x];
    }
    
    cout << answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
}
