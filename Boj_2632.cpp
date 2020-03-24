//Main idea: 피자 2개 각각으로 만들 수 있는 경우 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int ans = 0;
vector<int> arr1;
vector<int> arr2;

void Input() {
	int tmp, a, b;
	cin >> N >> a >> b;
	vector<int> vec1, vec2;
	for (int i = 0; i < a; i++) {
		cin >> tmp;
		vec1.push_back(tmp);
	}
	for (int i = 0; i < b; i++) {
		cin >> tmp;
		vec2.push_back(tmp);
	}

	for (int i = 0; i < a; i++) {//i에서 시작해서 cnt만큼 더한 것 저장
		int sum = 0;
		int end = a;
		if (i != 0)
			end = a - 1;
		for (int cnt = 0; cnt < end; cnt++) {
			int idx = i + cnt;
			if (idx >= a)
				idx -= a;
			sum += vec1[idx];
			if (sum > N)
				break;
			if (sum == N) {
				ans++;
				break;
			}
			arr1.push_back(sum);
		}
	}
	for (int i = 0; i < b; i++) {
		int sum = 0;
		int end = b;
		if (i != 0)
			end = b - 1;
		for (int cnt = 0; cnt < end; cnt++) {
			int idx = i + cnt;
			if (idx >= b)
				idx -= b;
			sum += vec2[idx];
			if (sum > N)
				break;
			if (sum == N) {
				ans++;
				break;
			}
			arr2.push_back(sum);
		}
	}
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());
}

int Bs(int val, int st, int en) {
	int mid = (st + en) / 2;
	if (arr2[mid] == val) {
		int tmp = 0;
		for (int i = mid; i >= 0; i--) {
			if (arr2[i] != val)
				break;
			tmp++;
		}
		for (int i = mid+1; i < arr2.size(); i++) {
			if (arr2[i] != val)
				break;
			tmp++;
		}
		return tmp;
	}
	if (st == en)
		return 0;
	if (arr2[mid] > val)
		return Bs(val, st, mid);
	else
		return Bs(val, mid + 1, en);
}

void Pizza() {
	Input();
	int before = -1;

	for (int i = 0; i < arr1.size(); i++) {
		if (i == 0 || arr1[i - 1] != arr1[i]) //처음인경우 이전과 다른 것인 경우 값 갱신
			before = Bs(N - arr1[i], 0, arr2.size() - 1);
		ans += before;
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Pizza();
}
