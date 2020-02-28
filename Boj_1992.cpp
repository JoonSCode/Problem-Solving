//Main idea: 1.올바르게 분할하는 것 2.모두 같은 수인지 
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isSame(string& str) {//모두 같은 수인지 확인
    char tmp = str[0];
    for (char& a : str) {
        if (tmp != a) 
            return false;
    }
    return true;
}

string quadTree(vector<vector<char>> arr, int startX, int endX, int startY, int endY){
    string ans ="";

    if (endX - startX == 1) {//base case
        string tmp = "";
        tmp += (arr[startX][startY]);
        tmp += (arr[endX][startY]);
        tmp += (arr[startX][endY]);
        tmp += (arr[endX][endY]);
        if (isSame(tmp))
            ans += tmp[0];
        else {
            ans = "(";
            ans += tmp;
            ans += ")";
        }
        return ans;
    }

    string tmp = "";//4분할
    tmp += quadTree(arr, startX, startX + (endX - startX) / 2, startY, startY + (endY-startY) / 2);//왼쪽 위
    tmp += quadTree(arr, startX + (endX - startX) / 2 + 1, endX, startY, startY + (endY - startY) / 2);//오른쪽 위
    tmp += quadTree(arr, startX, startX + (endX - startX) / 2, startY + (endY - startY) / 2 + 1, endY);//왼쪽 아래
    tmp += quadTree(arr, startX + (endX - startX) /2 + 1, endX, startY + (endY - startY) / 2 + 1, endY);//오른쪽 아래
    
    if (tmp.size() == 4 && isSame(tmp)) //모두 같은 수인경우 하나로 침
        ans += tmp[0];
    else {
        ans = "(";
        ans += tmp;
        ans += ")";
    }
 
    return ans;
}

vector<vector<char>> input() {//입력
    int N;
    cin >> N;
    vector<vector<char>> arr(N, vector<char>(N));

    for (int i = 0; i < N; i++) {
        for (int a = 0; a < N; a++) {
            char tmp;
            cin >> tmp;
            arr[a][i] = tmp;
        }
    }
    return arr;
}

int main() {
    ios::sync_with_stdio(false);
    vector<vector<char>> arr = input();
    cout << quadTree(arr, 0, arr.size()-1, 0, arr.size()-1);
}
