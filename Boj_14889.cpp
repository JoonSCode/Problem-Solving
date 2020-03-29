//Main idea: nextpermutation으로 조합 이용
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

vector<vector<int>> status;
int N;

void Input() {
	cin >> N;
	status.resize(N, vector<int>(N));

	int a;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a;
			status[i][j] = a;
		}
	}
}

int getVal(vector<int>& vec) {
	int val = 0;
	for (int i = 0; i < N / 2 - 1; i++) {
		int p1 = vec[i];
		for (int n = i + 1; n < N / 2; n++) {
			int p2 = vec[n];
			val += status[p1][p2];
			val += status[p2][p1];
		}
	}
	return val;
}

void Test() {
	Input();
	int answer = 9999999;
	vector<int> tmp(N,1);
	for (int i = 0; i < N / 2; i++)
		tmp[i] = 0;

	do {
		vector<int> t1, t2;
		for (int i = 0; i < N; i++) {
			if (tmp[i] == 0)
				t1.push_back(i);
			else
				t2.push_back(i);
		}
		answer = min(answer, abs((getVal(t1) - getVal(t2))));
	} while (next_permutation(tmp.begin(), tmp.end()));
	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Test();
}
