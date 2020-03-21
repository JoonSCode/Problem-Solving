//Main idea: 1. 숫자를 누적하여 배열에 저장 2. 모두 합하면 int범위 넘을 수 있으므로 주의!
#include <iostream>

using namespace std;

int N, M;
long long arr[10001];

void Input() {
	cin >> N >> M;
	int tmp;
	arr[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		arr[i] = arr[i-1] + tmp;
	}
}

void SumOfNum() {
	Input();
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			if (arr[j] - arr[i - 1] == M)
				answer++;
		}
	}
	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	SumOfNum();
}
