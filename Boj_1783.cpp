//Main idea: 경우를 세심하게 나눌 
#include <iostream>

using namespace std;

int Height, Width;

void input() {
    cin >> Height >> Width;
}

void OldKnight() {
    input();
    int answer = 1;
    if (Height == 1) {}//이동 불가
    else if (Height == 2) {//오른쪽으로 두칸 이동만 사용 가능한 경우
        if (Width < 2) {}
        else if (Width < 8)//이동 5번 미만인 경우
            answer += (Width - 1) / 2;
        else//4가지 방법으로 이동할 수 없지만 이동 5번 이상 가능한 경우
            answer = 4;
    }
    else if (Width < 5)
        answer = Width;
    else if (Width < 7) 
        answer = 4;
    else 
        answer = Width - 2;
    cout << answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    OldKnight();
}
