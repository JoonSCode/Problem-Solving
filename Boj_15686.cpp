//Main idea: 조합 + 거리구하기 함수
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

using namespace std;

int N, M;
vector<vector<int>> city;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

int getChicken(vector<pair<int,int>>& ch) {//치킨 거리 구하기
	int val = 0;
	for (pair<int, int>& h : house) {
		int dist = 987654321;
		int r = h.first;
		int c = h.second;
		for (pair<int, int>& chi : ch) 
			dist = min(dist, abs(r - chi.first) + abs(c - chi.second));
		val += dist;
	}
	return val;
}

void Run() {
	vector<int> tmp(chicken.size(), 1);
	for (int i = 0; i < M; i++)
		tmp[i] = 0;
	int answer = 987654321;
	do {
		vector<pair<int,int>> tmp_ch;
		for (int i = 0; i < tmp.size(); i++) //남는 치킨집 뽑는 조합
			if(tmp[i] == 0) tmp_ch.push_back(chicken[i]);
		answer = min(answer, getChicken(tmp_ch));
	} while (next_permutation(tmp.begin(), tmp.end()));
	cout << answer;
}

void Test() {
	cin >> N >> M;
	city.resize(N, vector<int>(N));
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			int a;
			cin >> a;
			if (a == 0)
				continue;
			if (a == 1)
				house.push_back({ y,x });
			else if (a == 2)
				chicken.push_back({ y,x });
		}
	}
	Run();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Test();
}
