//Main idea: 
#include <iostream>
#include<vector>
using namespace std;

void input(vector<vector<int>>&, const int&, const int&);//입력받는 함수
void Traversal(vector<vector<int>>&, const int&, const int&, int ,int);//순회 함수

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int w,h;
	vector<vector<int>> chart;	
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		chart.clear();
		chart.resize(h, vector<int>(w, 0));

		input(chart, w, h);

		int answer = 0;

		for (int i = 0; i < h; i++) {
			for (int n = 0; n < w; n++) {
				if (chart[i][n] != 0) {//바다가 아닌경우
					answer++;
					Traversal(chart, w, h, i, n);
				}
			}
		}
		cout << answer << "\n";
	}
}
void input(vector<vector<int>>& chart, const int& w, const int& h) {
	int a;
	for (int i = 0; i < h; i++) {
		for (int n = 0; n < w; n++) {
			cin >> a;
			chart[i][n] = a;
		}
	}
}
void Traversal(vector<vector<int>>& chart, const int& w, const int& h, int y, int x) {
	chart[y][x] = 0;//방문한 경우 바다로 처리하여 후에 연산되지 않도록 함
	pair<int, int> arr[8] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };//상하좌우 + 대각선까지 순회
	for (int i = 0; i < 8; i++) {
		int newY = y + arr[i].first;
		int newX = x + arr[i].second;
		if ((0 <= y + newY && newY  < h) && (0 <= newX && newX < w)) {
			if (chart[newY][newX] != 0)
				Traversal(chart, w, h, newY, newX);
		}
	}
}
