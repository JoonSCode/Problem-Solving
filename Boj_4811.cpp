//Main idea: 1.DP를 이용
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

long long dp[31][31];//한조각,반조각 갯수일 경우의 결과 값 저장

long long eat(int whole, int half) {  
    if (dp[whole][half] != 0)
        return dp[whole][half];
    if (whole == 0 && half == 0)
        return 1;
    long long answer = 0;
    if(whole != 0)
        answer += eat(whole - 1, half + 1);//약을 한조각 꺼낸 경우
    if (half != 0)
        answer += eat(whole, half - 1);//약을 반조각 꺼낸 경우
    dp[whole][half] = answer;
    return answer;
}

void pill() {
    int a = 0;
    memset(dp, 0, sizeof(dp));
    while (1) {
        cin >> a;
        if (a == 0)
            break;
        cout << eat(a,0) << "\n";
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    pill();
}
