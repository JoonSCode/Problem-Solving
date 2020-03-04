//Main idea: dp
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int dp[500][500];
int cost[500][500];

int triangle() {
	for (int i = 1; i < N; i++) {//한층씩 내려가며 값을 넣는다.
		dp[i][0] = dp[i - 1][0] + cost[i][0];//맨 앞과 뒤는 비교 없으므로 미리 처리
		dp[i][i] = dp[i - 1][i - 1] + cost[i][i];
		for (int n = 1; n <= i - 1; n++) {
			dp[i][n] = max(dp[i - 1][n - 1], dp[i - 1][n]) + cost[i][n];
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans, dp[N - 1][i]);
	}
	return ans;
}

void input() {
	memset(cost, -1, sizeof(cost));
	memset(dp, -1, sizeof(dp));
	cin >> N;
	int num;
	for (int i = 0; i < N; i++) {
		for (int n = 0; n <= i; n++) {
			cin >> num;
			cost[i][n] = num;
		}
	}
	dp[0][0] = cost[0][0];
}

int main() {
	input();

	cout << triangle();
}
