//Main idea: bfs를 수행하며 depth를 체크하기
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


vector<vector<int>> bowl;
vector<vector<int>> isVisited;
pair<int,int> order[4] = { {-1,0}, {0,-1}, {0,1},{1,0} };
int N, M, K;
int sharkSize = 2;
int eat;
int sy, sx;
int ans = 0;

int day = 0;


void input() {
    cin >> N;
    bowl.resize(N, vector<int>(N));
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            int t;
            cin >> t;
            if (t == 9) {
                t = 0;
                sy = y;
                sx = x;
            }
            bowl[y][x] = t;
        }
    }
}

bool bfs() {
    queue<pair<int,int>> que;
    que.push({ sy,sx });
    isVisited.clear();
    isVisited.resize(N, vector<int>(N, -1));
    isVisited[sy][sx] = 0;
    int candDepth = -1;
    int candY;
    int candX;
    while (!que.empty()) {
        int y = que.front().first;
        int x = que.front().second;
        int depth = isVisited[y][x];

        if (candDepth != -1 && candDepth <= depth) {//한사이클 지난 경우
            sy = candY;
            sx = candX;
            ans += candDepth;
            bowl[sy][sx] = 0;
            eat++;
            if (eat == sharkSize) {
                sharkSize++;
                eat = 0;
            }
            return true;
        }
        que.pop();

        for (pair<int, int>& o : order) {
            int ny = y + o.first;
            int nx = x + o.second;
            if (ny < 0 || nx < 0 || ny >= N || nx >= N || isVisited[ny][nx] != -1) continue;
            int& ret = bowl[ny][nx];
            if (ret > sharkSize) continue;
            isVisited[ny][nx] = depth + 1;

            if (ret == 0 || ret == sharkSize)
                que.push({ ny,nx });
            else {//나보다 크기 작은 것을 찾은 상태
                if (candDepth == -1 || depth + 1 < candDepth) {//찾은게 최초 혹은 이전 것 보다 가까운 경우 갱신
                    candY = ny;
                    candX = nx;
                    candDepth = depth + 1;
                }
                else if (depth + 1 == candDepth) {//거리 같을 때 위, 왼쪽 기준으로 확인하고 갱신
                    if (make_pair(ny, nx) > make_pair(candY, candX)) continue;
                    candY = ny;
                    candX = nx;
                    candDepth = depth + 1;
                }
            }

        }
    }

    if (candDepth != -1) {
        sy = candY;
        sx = candX;
        ans += candDepth;
        bowl[sy][sx] = 0;
        eat++;
        if (eat == sharkSize) {
            sharkSize++;
            eat = 0;
        }
        return true;
    }
    return false;
}

void solution() {
    input();

    while (bfs()) {}

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
}
