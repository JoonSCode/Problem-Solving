//Main idea: 한 층에서 움직일 수 있는 층을 연결된 노드로 생각하고 bfs
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int F, S, G, U, D;
int arr[1000001];

void Input() {
	cin >> F >> S >> G >> U >> D;
	memset(arr, -1, sizeof(arr));
}

void Run() {
	queue<int> que;
	que.push(S);
	arr[S] = 0;
	while (!que.empty()) {
		int num = que.front();
		int val = arr[num];
		que.pop();
		if (num + U <= F && arr[num + U] == -1) {//건물의 층 범위 안이며 아직 방문하지 않은 층의 경우 
			arr[num + U] = val + 1;
			if (num + U == G)
				break;
			que.push(num + U);
		}
		if (num - D > 0 && arr[num - D] == -1) {
			arr[num - D] = val + 1;
			if (num - D == G)
				break;
			que.push(num - D);
		}
	}
}

void StartLink() {
	Input();
	Run();
	if (arr[G] == -1)
		cout << "use the stairs";
	else
		cout << arr[G];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	StartLink();
}
