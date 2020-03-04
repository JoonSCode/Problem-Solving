//Main idea: dp에서 bottom up
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int cost[1000][3];
int dp[1000][3];
int N;

int RGB(int num) {
	for (int i = 1; i < N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
	}
	return min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2]));
}

void input() {//input & init
	memset(cost, 0, sizeof(cost));
	memset(dp, -1, sizeof(dp));
  
	cin >> N;
	int tmp;

	for (int i = 0; i < N; i++) {
		for (int n = 0; n < 3; n++) {
			cin >> tmp;
			cost[i][n] = tmp;
		}
	}
	dp[0][0] = cost[0][0];
	dp[0][1] = cost[0][1];
	dp[0][2] = cost[0][2];
}
int main() {
	input();
	cout<<RGB(N);
}
