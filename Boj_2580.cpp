//Main idea: 빈칸과 후보수를 체크 한후 백트래킹 한다.
#include <iostream>
#include <vector>

using namespace std;

struct blank {//빈칸의 좌표와 해당 하는 곳에 들어갈 수 있는 후보 수의 배열을 가진 구조체
	int x, y;
	vector<int> cand;
	blank(int a, int b) :x(a), y(b) {};
};

vector<vector<int>> Map(9, vector<int>(9));
vector<blank> blank_arr;

void Input() {//입력 
	int tmp;
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			cin >> tmp;
			Map[y][x] = tmp;
			if (tmp == 0)
				blank_arr.push_back(blank(x,y));
		}
	}
}

void FindCand(blank& a) {//후보 수 찾기
	int arr[10] = { 0, };
	const int& x = a.x;
	const int& y = a.y;

	for (int i = 0; i < 9; i++) {//가로 세로 확인
		arr[Map[y][i]]++;
		arr[Map[i][x]]++;
	}
	for (int sy = (y / 3) * 3; sy < ((y / 3) + 1) * 3; sy++) {//3*3 확인
		for (int sx = (x / 3) * 3; sx < ((x / 3) + 1) * 3; sx++)
			arr[Map[sy][sx]]++;
	}

	for (int i = 1; i < 10; i++) {//들어가지 않은 수만 후보가 될 수 있다.
		if (arr[i] == 0)
			a.cand.push_back(i);
	}
}

bool IsPossible(const int&y, const int&x, const int&val) {//현재 table이 유효한지 확인한다. val이 이번에 들어간 수
	for (int i = 0; i < 9; i++) {//가로 세로 확인 val과 같은 수가 있다면 오류
		if (i != x && Map[y][i] == val)
			return false;
		if (i != y && Map[i][x] == val)
			return false;
	}
	for (int sy = (y / 3) * 3; sy < ((y / 3) + 1) * 3; sy++) {//3*3 체크 가로 세로는 이미 체크해서 해당 하는 곳은 제외
		if (sy == y)
			continue;
		for (int sx = (x / 3) * 3; sx < ((x / 3) + 1) * 3; sx++) {
			if(sx == x)
				continue;
			if (Map[sy][sx] == val)
				return false;
		}
	}
	return true;
}

void Run(int idx) {//idx번째 것을 테스트
	if (idx == blank_arr.size()) {//다 찾은 경우
		for (int y = 0; y < 9; y++) {
			for (int x = 0; x < 9; x++) 
				cout << Map[y][x] << " ";
			cout << "\n";
		}
		exit(0);
	}

	blank& ret = blank_arr[idx];
	const int& x = ret.x;
	const int& y = ret.y;
	const vector<int>& cand = ret.cand;

	for (int a : cand) {
		Map[y][x] = a;
		if (IsPossible(y, x, a)) 
			Run(idx + 1);
	}
	Map[y][x] = 0;
}

void Sudoku() {
	Input();
	for (blank& a : blank_arr) 
		FindCand(a);
	Run(0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Sudoku();
}
