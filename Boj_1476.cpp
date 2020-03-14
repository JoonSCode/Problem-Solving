//Main idea: 
#include <iostream>

using namespace std;

int E, S, M;

void input() {
    cin >> E >> S >> M;
}

void Calculate() {
    input();
    long long ans = 1;
    int e = 1;
    int s = 1;
    int m = 1;
    if (e == E && s == S && m == M) {
        cout << ans;
        return;
    }
    while (1) {
        e++;
        s++;
        m++;
        ans++;
        if (e == 16)
            e = 1;
        if (s == 29)
            s = 1;
        if (m == 20)
            m = 1;
        if (e == E && s == S && m == M)
            break;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Calculate();
}
