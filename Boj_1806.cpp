//Main idea: 1.누적합 2.누적합이 목표 이상이 되는 곳 찾기
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
long long arr[100001];

int Input() {
	cin >> N >> M;
	int tmp;
	arr[0] = 0;
	int val = 0;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		arr[i] = arr[i-1] + tmp;
		if (val == 0 && arr[i] >= M)
			val = i;
	}
	return val;
}

void SumOfNum() {
	int end = Input();
	if (end == 0) {
		cout << "0";
		return;
	}
	int answer = N;
	for (int i = 1; i <= N; i++) {
    if(arr[N]- arr[i-1] <M)//i부터N 까지의 부분합이 M이 안되는 경우 그만한다.
      break;
		for (int j = max(i, end); j <= N; j++) {//시간 단축 위해 누적합이 목표 이상인 것부터 시작
			if (arr[j] - arr[i - 1] >= M) {
				answer = min(answer, j - i + 1);
				break;
			}
		}
	}
	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	SumOfNum();
}
