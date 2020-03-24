//Main idea: 경우가 너무 많을 경우 나눠서 생각하자.
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<vector<int>> arr;
vector<int> arr1;
vector<int> arr2;
long long ans = 0;


void Input() {
	cin >> N;
	int tmp;
	arr.resize(4, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int n = 0; n < 4; n++) {
			cin >> tmp;
			arr[n][i] = tmp;
		}
	}
}

void Divide() {//배열4개중 앞2개 뒤2개 나눠서 각각을 더해서 가능한 것들을 배열에 넣는다.
	for (int i = 0; i < N; i++) {
		int num = arr[0][i];
		for (int n = 0; n < N; n++) {
			int num2 = arr[1][n];
			long long sum = num + num2;
			arr1.push_back(sum);
		}
	}
	for (int i = 0; i < N; i++) {
		int num = arr[2][i];
		for (int n = 0; n < N; n++) {
			int num2 = arr[3][n];
			long long sum = num + num2;
			arr2.push_back(sum);
		}
	}
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());
}
void Bs(int val, int cnt, int st, int en) {//val값을 가진 것 찾는 이분탐색
	int mid = (st + en) / 2;
	if (arr2[mid] == val) {//arr2에서 val을 가진 것이 많을 수 있으므로 찾은 지점에서 양 옆으로 넓혀가며 찾는다.
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
		ans += (long long)tmp * (long long)cnt;
		return;
	}
	if (st == en)
		return;
	if (arr2[mid] > val)
		Bs(val, cnt, st, mid);
	else
		Bs(val, cnt, mid + 1, en);
}

void SumFourNum() {
	Input();
	Divide();
	int cnt = 0;
	for (int i = 0; i < arr1.size() - 1; i++) {
		cnt++;
		if (arr1[i + 1] == arr1[i]) 
			continue;
		Bs(-arr1[i], cnt, 0, arr2.size()-1);
		cnt = 0;
	}
	if (arr1[arr1.size() - 2] == arr1.back())
		Bs(-arr1.back(),cnt+1, 0, arr2.size()-1);
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	SumFourNum();
}
