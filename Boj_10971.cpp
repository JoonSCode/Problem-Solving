//Main idea: 1.TSP 문제이며 N이 10이하 이므로 완전 
#include <iostream>
#include <list>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int arr[10][10];

void input() {
	memset(arr, -1, sizeof(arr));
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			int a;
			cin >> a;
			arr[y][x] = a;
		}
	}
}

int run(list <int> li, int start, int now) {
	int ret = 987654321;
	li.remove(now);
	if (li.empty()) {
		if (arr[now][0] != 0) 
			return arr[now][0];
		return ret;
	}
	ret = 987654321;
	for (int to : li) {
		if(arr[now][to] != 0)
			ret = min(ret, run(li, now, to) + arr[now][to]);
	}
	return ret;
}

void TSP() {
	input();
	int ans = 987654321;
	list <int> li;
	for (int i = 1; i < N; i++) 
			li.push_back(i);
	for (int i = 1; i < N; i++) {
		if (arr[0][i] != 0)
			ans = min(ans, run(li, 0, i) + arr[0][i]);
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	TSP();
}
