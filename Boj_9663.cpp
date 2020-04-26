//Main idea: 백트래킹할 때 체크를 효율적으로
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <utility>

using namespace std;

int N;
int answer = 0;

bool isPossible(vector<pair<int, int>>& vec, const int& y, const int& x) {
	for (pair<int,int>& a: vec) {
		if (a.second == x) return false;
		if (abs(a.first - y) == abs(a.second - x)) return false;
	}
	return true;
}

void backTracking(vector<pair<int,int>> vec, int cnt) {
	for (int x = 0; x < N; x++) {
		if (!isPossible(vec, cnt, x)) continue;
		if (cnt == N - 1) { 
			answer++; 
			continue; 
		}
		vec.push_back({ cnt,x });
		backTracking(vec, cnt + 1);
		vec.pop_back();
	}
}

void test() {
	cin >> N;
	vector<pair<int, int>> vec;
	backTracking(vec, 0);
	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	test();
}
