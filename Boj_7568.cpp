//Main idea: 문제에서 제공하는 방법대로 랭크를 
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {//비교함수 pair.first만 가지고 비교한다.
	if (a.first < b.first)
		return true;
	return false;
}

vector<pair<int, int>> input() {//사람들의 정보를 받아오는 함수
	int num_of_person;
	cin >> num_of_person;
	vector<pair<int, int>> person_info;
	for (int i = 0; i < num_of_person; i++) {
		int a, b;
		cin >> a >> b;
		person_info.push_back({ a,b });
	}
	return person_info;
}


void rankBig() {
	vector<pair<int, int>> person_info = input();
	vector<pair<int, int>> bigger_than;//idx,나보다 큰 사람의 수 순으로 저장
	vector<int> answer(person_info.size(), 0);
	for (int i = 0; i < person_info.size(); i++) 
		bigger_than.push_back({ 0,i });

	for (int i = 0; i < person_info.size() - 1; i++) {
		for (int n = i + 1; n < person_info.size(); n++) {
			if (person_info[i].first > person_info[n].first&& person_info[i].second > person_info[n].second)
				bigger_than[n].first ++;
			else if(person_info[i].first < person_info[n].first&& person_info[i].second < person_info[n].second)
				bigger_than[i].first++;
		}
	}
  
	sort(bigger_than.begin(), bigger_than.end(), compare);

	for (int i = 0; i < person_info.size(); i++) 
		answer[bigger_than[i].second] = bigger_than[i].first + 1;

	for (int tmp : answer)
		cout << tmp << " ";
}

int main() {
	rankBig();
}
