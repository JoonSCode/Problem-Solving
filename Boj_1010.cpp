//Main idea: dp
#include <iostream>
#include <cstring>

using namespace std;

int N;
long long dp[30][30];//왼쪽 오른쪽에 각각 몇개의 지점이 있을 때 최대 경우의 수

long long bridge(int a, int b) {
	long long& ret = dp[a][b];
	if (ret != 0)
		return ret;
	if (a == 1)
		return ret = b;
	if (a == b)
		return ret = 1;
	for (int i = b-1; i >= a-1; i--) {
   		ret += bridge(a - 1, i);
	}
	return ret;
}


int main() {                                                           
	int T;
	cin >> T;
	for(int i = 0; i < 30; i++)
		memset(dp[i], 0, sizeof(long long) * 30);
	while (T--) {
		int a, b;
		cin >> a >> b;
		cout << bridge(a,b)<<"\n";
	}
}
