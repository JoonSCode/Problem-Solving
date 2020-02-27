//Main idea: 시뮬레이션
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

void printer() {
	int N, M;
	cin >> N >> M;
	queue<pair<int,int>> doc;//프린터 큐
	vector<int> priority;//중요도만 모아놓은 것
  
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		doc.push({ tmp,i });
		priority.push_back(tmp);
	}
  
	sort(priority.begin(), priority.end());//오름차순이 되도록 함 (뺄 때 효율적)
  
	int seq = 1;
	while(!doc.empty()){
		while (doc.front().first < priority[priority.size() - 1]) {//중요도 배열의 가장뒤(가장 큰 것) 과 비교하여 현재 문서의 중요도가 작다면 뒤로 보냄
			pair<int, int> tmp = doc.front();
			doc.pop();
			doc.push(tmp);
		}
		if (doc.front().second == M) {//찾는 순서의 문서가 뽑히는 경우
			cout << seq << "\n";
			break;
		}
		doc.pop();
		priority.pop_back();
		seq++;
	}
}

int main() {
	int T;
	cin >> T;
	while(T--)
		printer();
}
