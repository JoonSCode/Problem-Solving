//Main idea: 한 정점에서 나가는 간선은 하나!
#include <iostream>
#include<vector>
#include <unordered_map>
using namespace std;

int run(vector<int>&, const int&);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<bool>isGroup;
	int T;
	cin >> T;

	while (T--) {
		int num_of_student;
		cin >> num_of_student;

		int answer = num_of_student;
		isGroup.clear();
		isGroup.resize(num_of_student + 1, false);

		vector<int> graph(num_of_student+1);

		for (int i = 0; i < num_of_student; i++) {
			int a;
			cin >> a;
			graph[i + 1] = a;
		}

		cout << run(graph, num_of_student) << "\n";
	}
}
int run(vector<int>& graph, const int& num_of_student){
	int answer = num_of_student;
	unordered_map<int, int> isVisit;
	vector<int> visit_this_time;

	int start_idx = 0;

	for (int i = 1; i <= num_of_student; i++) {
		int num_to_visit = i;
		start_idx = isVisit.size();
		int visit_order = start_idx;
		while (1) {
			auto it = isVisit.find(num_to_visit);
			if (it == isVisit.end()) {//
				isVisit.insert({ num_to_visit, visit_order });
				num_to_visit = graph[num_to_visit];
				visit_order++;
			}
			else {
				if (start_idx > it->second)//순회하다가 이전에 방문한 곳을 만난 경우 -> 뒤의 결과가 같으므로 고려하지 않는다.
					break;
				else {
					answer -= (isVisit.size() - it->second);
					break;
				}
			}
		}
	}
	return answer;
}
