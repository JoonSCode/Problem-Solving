//Main idea: 범위 
#include <iostream>

using namespace std;

int cal(int num) {
    int ans = num;
    while (num != 0) {
        ans += num % 10;
        num /= 10;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int sz = to_string(N).size();
    for (int i = N - sz * 9; i <= N; i++) {
        if (i > 0 && cal(i) == N) {
            cout << i;
            break;
        }
        if (i == N)
            cout << 0;
    }
}
    
