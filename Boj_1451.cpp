//Main idea: 왼쪽 모서리에서 시작하는 사각형 하나를 정의 하면 나머지는 경우가 2가지 중 하나   summed area table을 쓰면 더욱 성능 향상 가능할 
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
int arr[100][100];

void input() {
    cin >> N >> M;
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < N; i++) {
        for (int a = 0; a < M; a++) {
            char t;
            cin >> t;
            arr[i][a] = t - '0';
        }
    }
} 

long long cal(int sh, int sw, int eh, int ew) {
    long long val = 0;
    for (int h = sh; h <= eh; h++) {
        for (int w = sw; w <= ew; w++) {
            val += arr[h][w];
        }
    }
    return val;
}

long long div(int sh, int sw, int eh, int ew) {
    long long val1 = 0;
    long long val2 = 0; 
    for (int w = sw; w <= ew; w++) //가로로는 w만큼 세로로 꽉 채워서
        val1 = max(val1, cal(sh, sw, eh, w) * cal(sh, w+1, eh, ew));
    
    for (int h = sh; h <= eh; h++) 
        val2 = max(val2, cal(sh, sw, h, ew) * cal(h + 1, sw, eh, ew));
 
    return max(val1, val2);
}


void Rectangle() {
    input();
    long long ans = 0;

    if (N == 1) {//세로 길이가 1인 경우   가로로만 자름
        for (int wsz = 0; wsz < M - 1; wsz++) 
            ans = max(ans, cal(0, 0, N - 1, wsz) * div(0, wsz + 1, N - 1, M - 1));
    }
    else if (M == 1) {//가로 길이가 1인 경우 세로로만 자름
        for (int hsz = 0; hsz < N - 1; hsz++) 
            ans = max(ans, cal(0, 0, hsz, 0) * div(hsz + 1, 0, N - 1, 0));       
    }
    else {

        for (int h = 0; h < N - 1; h++) {
            for (int wsz = 0; wsz < M; wsz++) {//가로 길이
                if (wsz == M - 1) //가로를 꽉 채우는 경우 아래 사각형을 두개로 나눠야 함
                    ans = max(ans, cal(0, 0, h, wsz) * div(h + 1, 0, N - 1, M - 1));
                
                ans = max(ans, cal(0, 0, h, wsz) * max((cal(0, wsz + 1, h, M - 1) * cal(h + 1, 0, N - 1, M - 1)), cal(0, wsz + 1, N - 1, M - 1) * cal(h + 1, 0, N - 1, wsz)));
            }
        }
        //세로로 꽉 채우는 경우 옆 사각형을 두개로 나눠야 함
        for (int wsz = 0; wsz < M - 1; wsz++) //가로 길이 
            ans = max(ans, cal(0, 0, N - 1, wsz) * div(0, wsz + 1, N - 1, M - 1));
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Rectangle();
}
