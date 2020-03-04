//Main idea: 1. 재귀 2. 연산자 
#include <vector>
#include <iostream>

using namespace std;

vector<pair<int, int>> dp(51, { -1,-1 });

pair<int,int> operator + (pair<int,int> a, pair<int,int> b) {
	pair<int, int> tmp;
	tmp.first = a.first + b.first;
	tmp.second = a.second + b.second;
	return tmp;
}

pair<int,int> fibonachi(int num) {
	pair<int,int>& ret2 = dp[num];
	if (ret2.first != -1 && ret2.second != -1)
		return ret2;
	return ret2 = fibonachi(num - 1) + fibonachi(num - 2);
}

int main() {
	dp[0] = { 1,0 };
	dp[1] = { 0,1 };
	int T;
	cin >> T;
	while (T--) {
		int num;
		cin >> num;
		pair<int, int> ans = fibonachi(num);
		cout << ans.first<<" " << ans.second << "\n";
	}
}
