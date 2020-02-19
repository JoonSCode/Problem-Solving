//Main idea: 1.하노이를 재귀를 이용하여 생각해 볼 것, 2.자료형으로 담을 수 없는 수의 경우 어떻게 처리할 것인지(pow가 제대로 동작하지 않음)
#include <vector>
#include <iostream>

using namespace std;

void hanoi(int N, int a, int b, int c) {
    if (N == 1) {
        cout << a << " " << c << "\n";
        return;
    }
    hanoi(N - 1, a, c, b);
    hanoi(1, a, b, c);
    hanoi(N - 1, b, a, c);
}

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    if (N == 1)//규칙을 만족하기 이전의 것 미리 처리
        cout << "1\n";
    else {//2^N -1을 만족하는 경우 
        char num[36];//100승은 long long으로도 표현 불가능 따로 곱 처리
        for (int i = 1; i < 36; i++)
            num[i] = '0';
        num[0] = '2';
        int max = 1;//자릿수를 표시하여 연산을 최소화함
        for (int i = 1; i < N; i++) {
            int carry = 0;
            for (int n = 0; n < max; n++) {
                int a = (int)(num[n] - '0');
                a *= 2;
                a += carry;
                carry = a / 10;
                if (carry != 0) {
                    num[n] = (a % 10) + '0';
                    if (n == max - 1) 
                        max++;
                }
                else
                    num[n] = a + '0';
            }
        }
        num[0] -= 1;
        for (int i = max - 1; i >= 0; i--)
            cout << num[i];
        cout << "\n";
    }

    if (N <= 20) 
        hanoi(N, 1, 2, 3);
}
    
