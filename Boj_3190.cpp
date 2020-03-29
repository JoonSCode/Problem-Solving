//Main idea: 뱀의 위치를 갱신할 때 순서를 조심해서 한다.
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <cmath>
#include <stack>
#include <cstring>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

int N, K, L;
vector<vector<int>> Map;
queue<pair<int, char>> Move;
vector<pair<int, int>> snake;

void Input() {
	cin >> N;
	Map.resize(N, vector<int>(N, 0));
	cin >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> y >> x;
		Map[y-1][x-1] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int t;
		char a;
		cin >> t >> a;
		Move.push({ t,a });
	}
}

bool check(const int& px, const int& py) {
	if (px < 0 || py < 0 || px >= N || py >= N)
		return false;
	if (Map[py][px] == 2)
		return  false;
	return true;
}



void Run() {
	pair<int, int> od[4] = { {0,1},{1,0},{0,-1},{-1,0} };//R,D,L,U     
	int px = 0;
	int py = 0;
	int t = 0;
	int order = 0;

	int next_t = Move.front().first;
	char next_dir = Move.front().second;
	Move.pop();
	snake.push_back({ 0,0 });

	while (1) {
		t++;
		px += od[order].second;
		py += od[order].first;
		if (!check(px, py))
			break;
		if (Map[py][px] == 1)
			snake.push_back({ py,px });
		else {
			Map[snake.front().first][snake.front().second] = 0;//지도에서 꼬리 위치를 바꾼다.
			for (int i = 0; i < snake.size()-1; i++) //뱀 위치 갱신
				snake[i] = snake[i + 1];
			snake.back() = { py,px };//뱀 머리 갱신
		}

		Map[py][px] = 2;//뱀 머리 부분 지도에 

		if (t == next_t) {//방향을 바꿀 때!
			if (next_dir == 'L') {//움직임에 따라 x,y변화량을 배열로 표현하여 사용 L일 경우 왼쪽, R일 경우 오른쪽(순환배열)
				if (order == 0)
					order = 3;
				else
					order--;
			}
			else {
				if (order == 3)
					order = 0;
				else
					order++;
			}
			if (!Move.empty()) {
				next_t = Move.front().first;
				next_dir = Move.front().second;
				Move.pop();
			}
		}
	}
	cout << t;
}

void Test() {
	Input();
	Run();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Test();
}
