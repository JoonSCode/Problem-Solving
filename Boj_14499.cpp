//Main idea: 주사위가 굴러갈 때 전개도의 변화를 함수로 만든다.
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

int N, M, K;
vector<vector<int>> Map;
vector<int> wi(3);
vector<int> hi(4);
queue<int> order;
pair<int, int> od[4] = { {0,1},{0,-1},{-1,0},{1,0} };//R,L,U,D
int r, c;//주사위 위치

void Input() {
	cin >> N >> M >> r >> c >> K;
	Map.resize(N, vector<int>(M, 0));
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			int num;
			cin >> num;
			Map[y][x] = num;
		}
	}
	for(int i = 0; i < K; i++) {
		int num;
		cin >> num;
		order.push(num);
	}
}

void moveR() {
	int last = wi[2];
	for (int i = 1; i >= 0; i--) 
		wi[i + 1] = wi[i];
	wi[0] = hi[3];
	hi[3] = last;
	hi[1] = wi[1];
}

void moveL() {
	int last = wi[0];
	for (int i = 1; i < 3; i++)
		wi[i - 1] = wi[i];
	wi[2] = hi[3];
	hi[3] = last;
	hi[1] = wi[1];
}
void moveD() {
	int last = hi[3];
	for (int i = 2; i >= 0; i--)
		hi[i + 1] = hi[i];
	hi[0] = last;
	wi[1] = hi[1];
}
void moveU() {
	int last = hi[0];
	for (int i = 1; i <= 3; i++)
		hi[i - 1] = hi[i];
	hi[3] = last;
	wi[1] = hi[1];
}

void Run() {
	while (!order.empty()) {

		int o = order.front();
		order.pop();
		pair<int,int> move = od[o-1];
		int nr = r + move.first;
		int nc = c + move.second;
		if (nr < 0 || nr >= N || nc < 0 || nc >= M)
			continue;
		switch (o){
		case 1:
			moveR();
			break;
		case 2:
			moveL();
			break;
		case 3:
			moveU();
			break;
		case 4:
			moveD();
			break;
		default:
			break;
		}
		r = nr;
		c = nc;

		if (Map[r][c] == 0) //주사위 값 
			Map[r][c] = hi[3];
		else {
			hi[3] = Map[r][c];
			Map[r][c] = 0;
		}

		cout << hi[1] << "\n";
	}
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
