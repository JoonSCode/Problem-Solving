//Main idea: next_permutation, prev_permutation을 이용하여 부분순열 
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void run() {
	int N, S;
	cin >> N >> S;
	vector<int> nums;
	int answer = 0;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		nums.push_back(tmp);
	}
	
	for (int i = 1; i <= N; i++) {//부분 수열의 크기
		vector<int> part(i,1);
		for (int n = 0; n < N - i; n++)
			part.push_back(0);

		do {
			int sum = 0;
			for (int i = 0; i < part.size(); i++) {
				if (part[i] == 1)
					sum += nums[i];
			}
			if (sum == S)
				answer++;
		} while (prev_permutation(part.begin(), part.end()));
	}
	cout << answer;
}

int main() {
	run();
}
