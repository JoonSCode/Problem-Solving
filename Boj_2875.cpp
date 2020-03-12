//Main idea: 그리디 
#include <iostream>

using namespace std;

int N, M, K;

void input() {
    cin >> N >> M >> K;
}

void Contest() {
    input();
    int max_team = min(N / 2, M);
    int num = N - max_team * 2+ M - max_team;
    while(K-num > 0){
        max_team--;
        num = N - max_team * 2 + M - max_team;
    }
    cout << max_team;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Contest();
}
