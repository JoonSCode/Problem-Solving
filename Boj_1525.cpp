//Main idea: 1. 총 경우의 수 9!으로 완전 탐색 가능 2. 1차원 행렬로 바꾸더라고 원래는 2차원 행렬임을 
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int Num;
unordered_map<int, int> cache;

void Input() {
	Num = 0;
	for (int i = 0; i < 9; i++) {
		Num *= 10;
		int t;
		cin >> t;
		if (t == 0)
			Num += 9;
		else
			Num += t;
	}
}

void run() {
	queue<int>que;
	que.push(Num);
	cache.insert({ Num, 0 });
	while (!que.empty()) {
		const int& num = que.front();
		const int& val = cache.find(num)->second;
		que.pop();
		vector<int> arr;

		string str = to_string(num);
		int idx = str.find('9');

		int idx_arr[4] = { idx + 3, idx - 1, idx - 3 , idx + 1 };

		for (int t : idx_arr) {
			if (t < 0 || t >= 9)
				continue;
			if (t == idx - 1 && (idx == 3 || idx == 6))//원래는 2차원 행렬이므로 행렬의 왼쪽끝일 때 -1할 수 없음
				continue;
			if (t == idx + 1 && (idx == 2 || idx == 5))//행렬의 오른쪽 끝일 떄 +1 할 수 없음
				continue;

			string tmp = str;
			char a = tmp[idx];//idx와 t위치에 있는 값을 교환 함
			tmp[idx] = tmp[t];
			tmp[t] = a;
			arr.push_back(atoi(tmp.c_str()));
		}

		for (int a : arr) {
			if (cache.find(a) == cache.end()) {
				cache.insert({ a, val + 1 });
				if (a == 123456789)
					return;
				que.push(a);
			}
		}
	}
}

void Puzzle() {
	Input();
	run();
	auto it = cache.find(123456789);
	if (it == cache.end())
		cout << "-1";
	else
		cout << it->second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Puzzle();
}
