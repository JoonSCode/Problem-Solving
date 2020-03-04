//Main idea: summed area table
#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int arr[300][300];

int SumOfArr() {
	int i, j, x, y;
	cin >> i >> j >> x >> y;
	i--;//값들이 1부터 시작하는 것 기준이므로 0 기준으로 맞추어 줌
	j--;
	x--;
	y--;
	if (i != 0 && j != 0) {
		return arr[x][y] + arr[i - 1][j - 1] - arr[i - 1][y] - arr[x][j - 1];
	}
	else if (i == 0 && j == 0)
		return arr[x][y];
	else if (i == 0) {
		return arr[x][y] - arr[x][j - 1];
	}
	else {
		return arr[x][y] - arr[i-1][y];
	}
}


void input() {//summed area table만든다.
	memset(arr, 0, sizeof(arr));
	int tmp;
	for (int i = 0; i < N; i++) {
		for (int n = 0; n < M; n++) {
			cin >> tmp;
			if (n == 0)
				arr[i][n] = tmp;
			else
				arr[i][n] = arr[i][n - 1] + tmp;
		}
	}
	for (int n = 0; n < M; n++) {
		for (int i = 1; i < N; i++) {
			arr[i][n] += arr[i - 1][n];
		}
	}
}

int main() {                                                           
	cin >> N >> M;
	input();
	int T;
	cin >> T;
	while(T--)
		cout << SumOfArr()<<"\n";
}
