//Main idea: 1. 1로 끝나는 경우 0으로 끝나는 경우를 합한다. 2. 연산도중에 숫자가 너무 커지지 않도록 한다.
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int cache[1000001];

int run(int N) {
    int& ret = cache[N];
    if (ret != -1)
        return ret;
    return ret = (run(N - 1) + run(N - 2)) % 15746;//뒤에 1로 끝나는 경우 00 으로 끝나는 경우를 합치면된다. 도중에 숫자가 너무 커지므로 미리 나머지 연산을 취한다.
}

void Tile(){
    int N;
    cin >> N;
    memset(cache, -1, sizeof(cache));
    cache[1] = 1;
    cache[2] = 2;
    cout <<  run(N);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Tile();
}
