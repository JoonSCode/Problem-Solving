//Main idea: 연산자들의 나열을 순열로 
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void cal() {
	int N;
	cin >> N;

	vector<long long> nums;
	vector<int> op;//+ - * /

	long long big = -2000000000;//문제의 조건을 만족하는 최대 최소 범위로 초기화
	long long small = 2000000000;

	for (int i = 0; i < N; i++) {
		long long tmp;
		cin >> tmp;
		nums.push_back(tmp);
	}
  
	for (int i = 0; i < 4; i++) {
		int tmp;
		cin >> tmp;
		while (tmp--)
			op.push_back(i);
	}

	do {//연산자들을 순열로 취급하여 연산
		long long num = nums[0];
		for (int i = 0; i < N - 1; i++) {
			switch (op[i]){
			case 0:
				num += nums[i + 1];
				break;
			case 1:
				num -= nums[i + 1];
				break;
			case 2:
				num *= nums[i + 1];
				break;
			case 3:
				if (num < 0 && nums[i + 1] > 0) {
					num = -(-num) / nums[i + 1];
				}
				else
					num /= nums[i + 1];
				break;
			default:
				break;
			}
		}
		big = max(big, num);
		small = min(small, num);

	} while (next_permutation(op.begin(), op.end()));

	cout << big << "\n" << small;
}

int main() {
	cal();
}
