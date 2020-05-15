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

void solution() {
	int N, M, B;
	int sum = 0;
	int min_val = 257;
	int max_val = 0;
	int time = 987654321;
	vector<int> land(257,0);

	cin >> N >> M >> B;

	for (int y = 0; y < N * M; y++) {
		int tmp;
		cin >> tmp;
		land[tmp] ++;
		sum += tmp;
		min_val = min(min_val, tmp);
	}
	int high = (sum + B) / (M * N);
	for (int i = min(256,high); i >= min_val; i--) {
		int t = 0;
		for (int n = 0; n < 257; n++) {
			if (n > i) t += (n - i) * 2 * land[n];
			else t += (i - n) * land[n];
			if (t >= time)
				break;
		}
		if (time <= t) continue;
		max_val = i;
		time = t;
	}
	cout << time << " " << max_val;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    solution();
}
