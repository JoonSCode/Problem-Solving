//Main idea: 1. 중간에서 데이터를 삭제해야할 경우가 많으므로 vector를 피한다. 2. 나무의 수가 많아질 수 있어 sort를 사용하지 않아야 한다.
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

struct tree {
    int y, x;
    int age;
    tree(int a, int b, int c) {
        y = a;
        x = b;
        age = c;
    }
};

vector<vector<int>> field;
vector<vector<int>> isVisited;
deque<tree> trees;
queue<tree> deadTrees;
vector<vector<int>> nut;
pair<int,int> order[8] = { {1,0},{1,1},{1,-1},{-1,1},{-1,0},{-1,-1},{0,1},{0,-1} };
int N, K;

bool cmp(const tree& a, const tree& b) {//y,x,age작은 순
    if (a.y < b.y) return true;
    if (a.y == b.y) {
        if (a.x < b.x) return true;
        if (a.x > b.x) return false;
        return a.age < b.age;
    }
    return false;
}

void spring() {
    int sz = trees.size();
    while (sz--) {
        tree a = trees.front();
        int ty = a.y;
        int tx = a.x;
        trees.pop_front();
        if (field[ty][tx] < a.age)
            deadTrees.push(a);
        else {
            field[ty][tx] -= a.age;
            a.age++;
            trees.push_back(a);
        }
    }
}

void summer() {
    while (!deadTrees.empty()) {
        tree& a = deadTrees.front();
        int ty = a.y;
        int tx = a.x;
        field[ty][tx] += a.age / 2;
        deadTrees.pop();
    }
}
void fall() {
    int sz = trees.size();
    queue<tree> tmp;
    while (sz--) {
        tree t = trees.front();
        trees.pop_front();
        tmp.push(t);
        if (t.age % 5 == 0) {
            for (pair<int, int>& a : order) {
                int ny = a.first + t.y;
                int nx = a.second + t.x;
                if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                trees.push_back(tree(ny, nx, 1));
            }
        }
    }
    while (!tmp.empty()) {
        trees.push_back(tmp.front());
        tmp.pop();
    }
}
void winter() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) 
            field[y][x] += nut[y][x];
    }
}

void input() {
    int M;
    cin >> N >> M >> K;
    field.resize(N, vector<int>(N, 5));
    isVisited.resize(N, vector<int>(N, 0));
    nut.resize(N, vector<int>(N, 0));

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            int tmp;
            cin >> tmp;
            nut[y][x] = tmp;
        }
    }

    for (int i = 0; i < M; i++) {
        int y, x, age;
        cin >> y >> x >> age;
        trees.push_back(tree(y - 1, x - 1, age));
    }
}

void solution() {
    input();
    while (K--) {
        spring();
        summer();
        fall();
        winter();
    }
    cout << trees.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
}
