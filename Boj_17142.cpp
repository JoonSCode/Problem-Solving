//Main idea: 모든 칸을 '활성' 바이러스로 채우는 것이 아니라 '바이러스'로 채우는 
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

int N, M;
vector<vector<int>> arr;
vector<pair<int, int>> virus;
pair<int, int> od[4] = { {0,1},{0,-1},{1,0},{-1,0} };
int blank;

void input() {
    cin >> N >> M;
    arr.resize(N, vector<int>(N));
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            int tmp;
            cin >> tmp;
            if (tmp == 2) 
                virus.push_back({ y,x });
            if (tmp == 0)
                blank++;
            arr[y][x] = tmp;
        }
    }
}

int bfs(vector<vector<int>>& vec, queue<pair<int, int>>& que) {
    int ans = 0;
    int cnt = 0;
    while (!que.empty()) {
        int y = que.front().first;
        int x = que.front().second;
        int val = vec[y][x];
        que.pop();
        for (pair<int, int>& a : od) {
            int nx = a.second + x;
            int ny = a.first + y;
            if (nx < 0 || ny < 0 || nx >= N || ny >= N || vec[ny][nx] == 1 || vec[ny][nx]>2) continue;//범위 밖, 벽, 바이러스인경우 제외
            if (vec[ny][nx] == 0)
                cnt++;
            vec[ny][nx] = val + 1;
            ans = val + 1;
            
            if (cnt == blank) {//모든 칸이 '활성'바이러스가 되는 것이 아닌 '바이러스'로 채우는 것이므로 빈칸을 채운 것만 확인한다.
                while (!que.empty())//큐를 모두 비워 후에 데이터 꼬이지 않도록 한다.
                    que.pop();
            }
            else
                que.push({ ny,nx });
        }
    }
    if (cnt == blank) return ans - 3;
    return -1;
}

int run() {
    int answer = 987654321;
    vector<int> tmp(virus.size(), 1);//비활성 바이러스 중 m개를 선택하고 bfs를 통해 확인하여 본다.
    for (int i = 0; i < M; i++)
        tmp[i] = 0;
    do {
        vector<vector<int>> vec = arr;
        queue<pair<int, int>> que;
        for (int i = 0; i < virus.size(); i++) {
            if (tmp[i] == 0) {
                vec[virus[i].first][virus[i].second] = 3;
                que.push({ virus[i].first ,virus[i].second });
            }
        }
        int ta = bfs(vec, que);
        if(ta != -1)
            answer = min(ta, answer);
    } while (next_permutation(tmp.begin(), tmp.end()));
    if (answer == 987654321)
        return -1;
    return answer;
}

void solution() {
    input();
    if (blank == 0) cout << "0";
    else
        cout << run();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
}
