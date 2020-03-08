//
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree(100001);
vector<int> cache(100001,0);
int N;

void input() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
}

void run(int a) {//a에 연결되어 있는 노드 중 아직 부모가 정해지지 않았으면 a가 부모이다.
    for (int n : tree[a]) {//인접리스트
        int& ret = cache[n];
        if (ret == 0) {//부모 노드를 아직 모르는 경우만 재귀
            ret = a;
            run(n);
        }
    }
}

void TreeParent(){
    input();
    run(1);
    for (int i = 2; i <= N; i++)
        cout << cache[i] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    TreeParent();
}
