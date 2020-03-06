//Main idea: 
#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> cache(1001, vector<long long>(501, -1));

long long change(int a, int b) {
    if (b > a - b)//b를 무조건 작은 값으로 해서 cache의 크기를 줄임
        b = a - b;
    if (b == 1)//base case
        return a;
    if (b == 0)
        return 1;
    long long& ret = cache[a][b];
    if (ret != -1)
        return ret;
    return ret = (change(a - 1, b) + change(a - 1, b - 1)) % 10007;//파스칼의 법칙
}

void Coefficient2(){
    int N, K;
    cin >> N >> K;
    cout << change(N, K);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Coefficient2();
}
