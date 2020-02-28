//Main idea: 효율적으로 재귀를 돌리기

//원래 arr을 파라미터로 넣었는데 실수로 call by value로 해서 시간초과가 났음! 주의!
#include <iostream>
#include <vector>

using namespace std;

int answer[4] = { 0, };
vector<vector<int>> arr;

int paper(int startX,  int startY, int width){
    if (width == 2) {//base case
        int tmp[3] = { 0, };
        int a = arr[startX][startY];
        bool isSame = true;
        for (int i = startX; i <= startX+ width; i++) {//한가지로 구성되어 있는지 확인
            for (int n = startY; n <= startY+ width; n++) {
                if (isSame && a != arr[i][n])
                    isSame = false;
                tmp[arr[i][n] + 1] ++;
            }
        }
        if (isSame) //-1,0,1을  0,1,2idx에 넣기 위해 +1
            return a + 1;
        else {//해당하는 각각을 정답에 더해준다. 3을 여기서 각각 다른 경우 재귀를 타고 올라가도 의미 없는 값이므로 미리 답에 더하고 3이라는 의미 없는 값 반환
            answer[0] += tmp[0];
            answer[1] += tmp[1];
            answer[2] += tmp[2];
            return 3;
        }
    }

    int size = width / 3;
    vector<int> tmp;
    bool isSame = true;

    for (int i = startY; i < startY +width; i += size + 1) {//9가지 부분에 대해서 재귀
        for (int n = startX; n < startX + width; n += size + 1) 
            tmp.push_back(paper(n, i, size));
    }

    for (int i = 0; i < 8; i++) {//모두 같은 구성요소인지 확인
        if (tmp[i] != tmp[i + 1]) {
            isSame = false;
            break;
        }
    }

    if (isSame) {//tmp[0] 이 3이어도 상관없다. 닶에 보여주지 않기 때문
        return tmp[0];
    }
    else {
        for (int n : tmp) {
            answer[n]++;
        }
        return 3;
    }
}

void input() {//입력
    int N;
    cin >> N;
    arr.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int a = 0; a < N; a++) {
            int tmp;
            cin >> tmp;
            arr[a][i] = tmp;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    answer[paper(0, 0, arr.size() - 1)]++;//모두 한가지 구성요소인 경우 위해
    cout << answer[0] << "\n" << answer[1] << "\n" << answer[2];
}
