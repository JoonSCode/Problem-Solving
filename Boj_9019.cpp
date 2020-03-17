//Main idea: 1. 레지스터는 숫자 자리수와 상관없이 4개이다. 2.string은 길어질수록 복사에 소요시간이 크다.
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int N, M;
vector<string> cache;
vector<int> from;

void Input() {
	cin >> N >> M;
	cache.clear();
	cache.resize(10000,  "A" );
	from.clear();
	from.resize(10000,  -1);
}

void run() {
	queue<int>que;
	cache[N] = "";
	que.push(N);
	char order[4] = { 'D','S','L','R' };
	while (!que.empty()) {
		int num = que.front();
		string& val = cache[num];
		que.pop();
		int arr[4];//먼저 D S L R 숫자 배열을 만든다.
		arr[0] = num * 2 % 10000;
		if (num == 0)
			arr[1] = 9999;
		else
			arr[1] = num - 1;

		vector<int> tmp(4, 0);//레지스터가 4개이기 때문! 숫자가 2자리 수일 때도 레지스터는 4개!
		int idx = 3;
		while (num != 0) {
			tmp[idx] = num % 10;
			num /= 10;
			idx--;
		}
		arr[2] = ((tmp[1] * 10 + tmp[2]) * 10 + tmp[3]) * 10 + tmp[0];
		arr[3] = ((tmp[3] * 10 + tmp[0]) * 10 + tmp[1]) * 10 + tmp[2];
		

		for (int i = 0; i < 4; i++) {//탐색하지 않은 경우 큐에 넣는다.
			string& ret = cache[arr[i]];
			if (ret == "A") {
				ret = val + order[i];
				if (arr[i] == M)
					return;
				que.push(arr[i]);
			}
		}
	}
}

void DSLR() {
	int T;
	cin >> T;
	while (T--) {
		Input();
		run();
		cout << cache[M] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	DSLR();
}
