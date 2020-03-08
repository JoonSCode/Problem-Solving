//Main idea: 일정 값을 구하고 그 값에 해당하는 확인 연산 -> 그에 따른 이분탐색 범위 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> house;
int N, M;

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        house.push_back(tmp);
    }
    sort(house.begin(), house.end());
}

bool put(int& num){ //최소 num 간격 이상으로 배치 가능한가?
    int dot = house[0];
    int t = 1;
    for (int i = 1; i < M; i++) {
        while (house[t]  < num + dot) {
            t++;
            if (t == house.size())
                return false;
        }
        dot = house[t];
    }
    return true;
}

int bs(int start, int end) {
    int ans = -1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (put(mid)) {
            ans = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return ans;
}

void Router() {
    input();
    cout << bs(1, house[house.size()-1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Router();
}
