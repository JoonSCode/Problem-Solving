//Main idea: 음수 사이클 찾기
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

vector<vector<int>> arr;
int numOfPoint;

void init() {
	arr.clear();
	arr.resize(500, vector<int>(500, 987654321));
}

void input(){
	int numOfRoad, numOfHole;
	cin >> numOfPoint >> numOfRoad >> numOfHole;
	while (numOfRoad--) {
		int s, e, t;
		cin >> s >> e >> t;
		s--; e--;
		arr[s][e] = arr[e][s] = min(arr[e][s], t);
	}
	while (numOfHole--) {
		int s, e, t;
		cin >> s >> e >> t;
		s--; e--;
		arr[s][e] = min(arr[s][e], -t);
	}
}


bool solution() {
	init();
  input();
  
	for (int k = 0; k < numOfPoint; k++) {
		for (int i = 0; i < numOfPoint; i++) {
			for (int j = 0; j < numOfPoint; j++) {
				if (arr[i][k] != 987654321 && arr[k][j] != 987654321) {
					arr[i][j] = min(arr[i][k] + arr[k][j], arr[i][j]);
					if (i == j && arr[i][j] < 0) return true;				
				}
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		if (solution())		cout << "YES\n";
		else	cout << "NO\n";
	}
}
