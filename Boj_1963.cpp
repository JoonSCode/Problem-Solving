//Main idea: 1.소수 찾기 2.자리수 별로 하나씩 바꿔가며 값 
#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

int N, M;
int  is_prime[10000];
int cache[10000];

void Input() {
	cin >> N >> M;
	memset(cache, -1, sizeof(cache));
}

void MakePrimeSet() {//에라토스테네스의 체
	memset(is_prime, 0, sizeof(is_prime));//0이면 소수 
	for (int i = 2; i < 5000; i++) {
		if (is_prime[i] == 0) {
			for (int n = 2; i * n < 10000; n++)
				is_prime[i * n] = 1;
		}
	}
}

void run(queue<int>& que) {
	while (!que.empty()) {
		int num = que.front();
		int val = cache[num];
		que.pop();

		int arr[4];
		int tmp = num;
		for (int i = 0; i < 4; i++) {//1의 자리 10의 자리 100의 자리 1000의 자리값 가지는 배열 생성
			arr[i] = tmp % 10;
			tmp /= 10;
		}

		for (int i = 0; i < 4; i ++) {//1의 자리부터 변경
			int mul = pow(10, i);//바꾸는 자리 수
			int new_num = num - arr[i] * mul;
			for (int n = 0; n < 10; n++) {
				if (i == 3 && n == 0)
					continue;
				int& ret = cache[new_num + mul * n];//자리 수 중 하나를 변경하여 만들 수 있는 숫자
				if (is_prime[new_num + mul * n] == 0 && (ret == -1 || ret > val + 1)) {//소수 &&( 아직 탐색 X || 더 작은 값 찾음)
					ret = val + 1;
					que.push(new_num + mul * n);
				}
			}
		}
	}
}

void PRIMEPATH() {
	MakePrimeSet();
	int T;
	cin >> T;
	while (T--) {
		Input();
		queue<int>que;
		que.push(N);
		cache[N] = 0;
		run(que);
		if (cache[M] == -1)
			cout << "Impossible\n";
		else
			cout << cache[M]<<"\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	PRIMEPATH();
}
