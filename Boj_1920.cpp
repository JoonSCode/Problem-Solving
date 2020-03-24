//Main idea: 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N,M;
vector<int> arr;
vector<int> q;

void Input() {
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		q.push_back(tmp);
	}
}

bool Bs(const int val, const int st, const int en) {
	int mid = (st + en) / 2;
	if (arr[mid] == val)
		return true;
	if (st == en)
		return false;
	if (arr[mid] > val)
		return Bs(val, st, mid);
	return Bs(val, mid + 1, en);
}

void FindNum() {
	Input();
	for (int a : q) {
		if (Bs(a, 0, arr.size() - 1))
			cout << "1\n";
		else
			cout << "0\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	FindNum();
}
