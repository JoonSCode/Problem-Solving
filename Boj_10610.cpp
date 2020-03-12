//Main idea: 30의 배수는 모든 자리 수 합이 3의 배수, 1의 자리가 0
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string num;

void input() {
    cin >> num;
}

bool cmp(const int& a, const int& b) {
    return a > b;
}

void Contest() {
    input();
    int cnt_zero = 0;
    int sum = 0;
    vector<char> vec;
    for (char a : num) {
        if (a == '0') {//0은 3의 배수 판별에 필요 없음
            cnt_zero++;
        }
        else
            vec.push_back(a);
        sum = (sum + a - '0') % 3;//수가 도중에 너무 커지지 않게 계속 3의 나머지 연산을 함
    }
    if (cnt_zero == 0 || sum != 0) {//0이 없거나 3의 배수가 아닌 경우 만들 수 없음
        cout << "-1";
        return;
    }
    sort(vec.begin(), vec.end(), cmp);//역순 정렬후 0을 넣어줌
    for (char a : vec)
        cout << a;
    while (cnt_zero--)
        cout << "0";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Contest();
}
