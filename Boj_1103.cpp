//Main idea: 1.재귀 사용시 stack를 초과하는 것을 피해야한다 2.dp를 이용하여 시간을 줄인다. 3.cycle을 잘 탐지한다.
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> dp;

int run(vector<vector<int>>& box, int now) {//x,y에서의 최대 이동 수
    if (dp[now] != -2) //들른 적 있음
        return dp[now];
    dp[now] = -1;//지금 탐색 중
    int ans = 0;
    for (int i = 0; i < box[now].size(); i++) {//연결된 곳으로 이동
        int result = run(box, box[now][i]);//갔을 때 결과
        if (result == -1)//탐색 중인 것을 방문한 경우 -> Cycle
            return -1;
        ans = max(ans, result);
    }
    ans += 1;//연결된 곳에서 움직일 수 있는 최대치 + 내가 연결된 곳으로 움직이는 것(1)
    dp[now] = ans;
    return ans;
}

void game(){
    int y, x;
    cin >> y >> x;
    vector<vector<int>> box(y * x);//vertex를 1자로 배열함
    dp.resize(y * x, -2);
    for (int i = 0; i < y * x; i++) {
        char tmp;
        cin >> tmp;
        if (tmp != 'H') {//유향 그래프로 변경
            int move = tmp - '0';
            if (0 <= i - move * x)//위로 갈 수 있는 경우
                box[i].push_back(i - move * x);
            if (i + move * x < y * x)//아래로
                box[i].push_back(i + move * x);
            if (i >= move && (i - move) / x == i / x)//왼쪽
                box[i].push_back(i - move);
            if ((i + move) / x == i / x)//오른쪽
                box[i].push_back(i + move);
            if (box[i].size() == 0)//마지막 움직임을 미리 dp에 넣음
                dp[i] = 1;
        }
        else//H인 경우 마지막으로 움직이는게 아닌 끝이므로 dp에 0을 넣음
            dp[i] = 0;
    }
    cout << run(box, 0);
}

int main() {
    ios::sync_with_stdio(false);
    game();
}
