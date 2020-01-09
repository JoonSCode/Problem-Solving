//Main idea: 정점당 간선이 한개인 유향 그래프 -> 사이클 == union 갯수 
#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {//union find를 위한 클래스 정의
private:
	int parent;
	int val;
public:
	DisjointSet(int _val);
	bool Union(DisjointSet& a);
	bool find(DisjointSet& a);
	void setParent(int& a);
	int getParent();
	~DisjointSet() {}
};

vector<DisjointSet> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	bool err;
	int T;
	cin >> T;
	while (T--) {
		vec.clear();
		vec.push_back(DisjointSet(0));
		//정점과 간선의 갯수 받아오기
		int N;
		cin >> N;
		int answer = N;//Union의 갯수

		for (int i = 0; i < N; i++) {
			vec.push_back(DisjointSet(i + 1));
		}
		//간선의 정보 받아오기
		for (int i = 1; i <= N; i++) {
			int a;
			cin >> a;
			if (vec[a].Union(vec[i])) 
				answer--;
		}
		cout << answer << "\n";
	}
}

DisjointSet::DisjointSet(int _val) {
	parent = _val;
	val = _val;
}
bool DisjointSet :: Union(DisjointSet& a) {
	if (find(a)) {
		a.setParent(parent);
		return true;
	}
	else {
		return false;
	}
}
bool DisjointSet :: find(DisjointSet& a) {
	bool ans;
	while (vec[parent].getParent() != parent) {//find 수행시마다 부모 갱신
		parent = vec[parent].getParent();
	}
	a.getParent() != parent ? ans = true : ans = false;
	return ans;
}
void DisjointSet::setParent(int& a) {
	parent = a;
}
int DisjointSet::getParent() {
	return parent;
}
