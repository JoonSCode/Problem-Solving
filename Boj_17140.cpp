//Main idea: 1. 정렬에 사용할 cmp함수 주의 2. 연산 후 쓰레기값 없애기
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

int R, C, K;
int row = 3;
int col = 3;
vector<vector<int>> arr(100, vector<int>(100, 0));

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

void input() {
    cin >> R >> C >> K;
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            int t;
            cin >> t;
            arr[y][x] = t;
        }
    }
}

void runR() {
    for (int y = 0; y < col; y++) {
        vector<int> tmp(101, 0);
        for (int x = 0; x < row; x++) 
            tmp[arr[y][x]]++;

        vector<pair<int, int>> vec;
        for (int i = 1; i <= 100; i++) {
            if (tmp[i] == 0) continue;
            vec.push_back({ i,tmp[i] });
        }
        sort(vec.begin(), vec.end(), cmp);
        row = max(row, min(50, (int)vec.size()) * 2);
        for (int x = 0; x < min(50, (int)vec.size()); x++) {
            arr[y][x * 2] = vec[x].first;
            arr[y][x * 2 + 1] = vec[x].second;
        }
        if (min(50, (int)vec.size()) != 50) {//새로 갱신하고 남은 것들 0으로 초기화
            for (int x = min(50, (int)vec.size())*2; x < 100; x++) 
                arr[y][x] = 0;
        }
    }
}
void runC() {
    for (int x = 0; x < row; x++){
        vector<int> tmp(101, 0);
        for (int y = 0; y < col; y++) 
              tmp[arr[y][x]]++;

        vector<pair<int, int>> vec;
        for (int i = 1; i <= 100; i++) {
            if (tmp[i] == 0) continue;
            vec.push_back({ i,tmp[i] });
        }
        sort(vec.begin(), vec.end(), cmp);
        col = max(col, min(50, (int)vec.size()) * 2);
        for (int y = 0; y < min(50, (int)vec.size()); y++) {
            arr[y*2][x] = vec[y].first;
            arr[y*2+1][x] = vec[y].second;
        }
        if (min(50, (int)vec.size()) != 50) {
            for (int y = min(50, (int)vec.size())*2; y < 100; y++)
                arr[y][x] = 0;
        }
    }
}

void run() {
    if (row <= col)runR();
    else runC();
}

void solution() {
    input();
    int ans = 0;
    while (arr[R-1][C-1] != K && ans <= 100) {
        run();
        ans++;
    }
    if (ans > 100)
        cout << "-1";
    else
        cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
}
