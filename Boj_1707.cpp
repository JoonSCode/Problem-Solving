//Main idea: 모든 정점은 두개의 그룹 중 하나에 속해야 한다.
#include <iostream> 
#include <vector>
#include <list>

using namespace std;

vector<list<int>> g_data;
vector<int> groupOfVertex;

bool err;

void dfs(int start, int group) {//시작점과 그룹번호를 파라미터로 가진다.
	groupOfVertex[start] = group;
	for (int adj : g_data[start]) {
		if (err)//이미 이분그래프가 아님이 판별난 경우 바로 종료한다.
			return;
		if (groupOfVertex[adj] == 0) {//인접한 정점이 탐색하지 않은 정점인 경우
			if (group == 1)//나와 다른 그룹으로 묶는다.
				dfs(adj, 2);
			else
				dfs(adj, 1);
		}
		else if (groupOfVertex[adj] == group) {//인접한 정점이 나와 같은 그룹인경우 -> 이분그래프가 아니다.
			err = 1;
			return;
		}
		else {}
	}
}

void init(int& V) {
	err = 0;
	g_data.clear();
	groupOfVertex.clear();

	g_data.resize(V + 1);
	groupOfVertex.resize(V + 1, 0);

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int V, E;
		cin >> V >> E;

		init(V);

		for (int i = 0; i < E; i++) {//인접 리스트로
			int a, b;
			cin >> a >> b;
			g_data[a].push_back(b);
			g_data[b].push_back(a);
		}
		for (int i = 1; i < V; i++) {//연결 그래프가 아닌 경우가 존재 할 수 있으므로
			if(groupOfVertex[i] == 0)
				dfs(i, 1);
		}

		if (err)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}
