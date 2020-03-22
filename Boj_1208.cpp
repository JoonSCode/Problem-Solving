//Main idea: 1. 부분수열은 순서를 유지하며 뽑는 것(연속 될 필요는 없다) 2. 부분수열을 나눠서 경우를 생각할 수 있다.
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int N, M;
vector<int> arr;
int answer = 0;
unordered_map<int, int> le;//key:만들 수 있는 수 val:만드는 방법의 수
unordered_map<int, int> ri;

void Run(int num) {//배열의 왼쪽 절반에서 num개를 골라서 만들 수 있는 것들을 map에 저장해서 사용
	vector<int> tmp;
	int sz = arr.size();
	for (int i = 0; i < num; i++)
		tmp.push_back(0);
	for (; num < sz; num++)
		tmp.push_back(1);

	do {
		int sum = 0;
		for (int i = 0; i < sz; i++) {
			if (tmp[i] == 0)
				sum += arr[i];
		}
		auto it = le.find(sum);
		if (it == le.end())
			le.insert({ sum, 1 });
		else
			it->second++;
	} while (next_permutation(tmp.begin(), tmp.end()));
}

void Run2(int num) {
	vector<int> tmp;
	int sz = arr.size();
	for (int i = 0; i < num; i++)
		tmp.push_back(0);
	for (; num < sz; num++)
		tmp.push_back(1);

	do {
		int sum = 0;
		for (int i = 0; i < sz; i++) {
			if (tmp[i] == 0)
				sum += arr[i];
		}
		auto it = ri.find(sum);
		if (it == ri.end())
			ri.insert({ sum, 1 });
		else
			it->second++;
	} while (next_permutation(tmp.begin(), tmp.end()));
}

void Input() {
	cin >> N >> M;
	int tmp;
	for (int i = 0; i < N/2; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}
	for (int i = 1; i <= arr.size(); i++)
		Run(i);
	arr.clear();
	for (int i = N / 2; i < N; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}
	for (int i = 1; i <= arr.size(); i++)
		Run2(i);
}

void SumOfNum() {
	Input();

	long long answer = 0;
	for (pair<int,int> a : le) {
		int num = a.first;
		int val = a.second;
		auto it = ri.find(M - num);
		if (num == M)//왼쪽 부분수열에서만 고르는 경우 더하기 위해 사용
			answer += val;
		if (it != ri.end())
			answer += (long long) val * (long long)it->second;
	}

	for (pair<int, int> a : ri) {//오른쪽 부분수열에서만 고르는 경우 더하기 위해 사용
		int num = a.first;
		int val = a.second;
		if (num == M)
			answer += val;
	}
	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	SumOfNum();
}
