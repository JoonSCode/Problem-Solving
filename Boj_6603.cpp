//Main idea: prev_permutation 
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void lotto(int size) {
	vector<int> num_set;
	for (int i = 0; i < size; i++) {
		int tmp;
		cin >> tmp;
		num_set.push_back(tmp);
	}

	vector<int> r_set;
	for (int i = 0; i < 6; i++)
		r_set.push_back(1);
	for (int i = 0; i < size - 6; i++)
		r_set.push_back(0);

	//순열
	do {
		// 출력
		for (int i = 0; i < r_set.size(); i++) {
			if (r_set[i] == 1) {
				cout<< num_set[i]<<" ";
			}
		}
		cout<<"\n";

	} while (prev_permutation(r_set.begin(), r_set.end()));
}

int main() {
	int T = -1;
	while (1) {
		cin >> T;
		if (T == 0)
			break;
		lotto(T);
		cout << "\n";
	}
}
