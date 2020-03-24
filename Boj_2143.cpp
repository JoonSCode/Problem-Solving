//Main idea: 1.누적합 2. 이분탐색 3.수의 범위에 유의
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int TARGET;
vector<long long> sa;
vector<long long> sb;
vector<long long> arr1;
vector<long long> arr2;

void Input() {
	int n, m;
	cin >> TARGET >> n;
	int tmp;
	arr1.resize(n + 1);

	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		sum += tmp;
		arr1[i+1] = sum;
	}

	cin >> m;
	sum = 0;
	arr2.resize(m + 1);
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		sum += tmp;
		arr2[i + 1] = sum;
	}
}

void Make() {//누적합을 이용하여 부분합 경우를 구한다.
	for (int i = 1; i < arr1.size(); i++) {
		for (int j = 0; i + j < arr1.size(); j++) {
			long long tmp = arr1[j+i] - arr1[i - 1];
			sa.push_back(tmp);
		}
	}
	for (int i = 1; i < arr2.size(); i++) {
		for (int j = 0; i + j < arr2.size(); j++) {
			long long tmp = arr2[j+i] - arr2[i - 1];
			sb.push_back(tmp);
		}
	}
	sort(sa.begin(), sa.end());
	sort(sb.begin(), sb.end());
}

int Bs(const int val, const int st, const int en) {
	int mid = (st + en) / 2;
	if (sb[mid] == val) {
		int cnt = 0;
		for (int i = mid; i >= 0; i--) {
			if (sb[i] != val)
				break;
			cnt++;
		}
		for (int i = mid + 1; i < sb.size(); i++) {
			if (sb[i] != val)
				break;
			cnt++;
		}
		return cnt;
	}
	if (st == en)
		return 0;
	if (sb[mid] > val)
		return Bs(val, st, mid);
	return Bs(val, mid + 1, en);
}

void SumOfArr() {
	Input();
	Make();
	long long before = 0;
	long long ans = 0;
	for (int i = 0; i < sa.size(); i++) {
		if (i == 0 || sa[i - 1] != sa[i]) 
			before = Bs(TARGET - sa[i], 0, sb.size() - 1);
		ans += before;
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	SumOfArr();
}
