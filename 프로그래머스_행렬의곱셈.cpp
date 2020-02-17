//Main idea: 행렬의 
#include <string>
#include <vector>

using namespace std;


int mul(vector<int>& a, vector<int>& b) {
    int num = 0;
    for (int i = 0; i < a.size(); i++)
        num += a[i] * b[i];
    return num;
}


vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size());

    vector<vector<int>> nums(arr2[0].size(), vector<int>(arr2.size()));//행렬 변환
    for (int i = 0; i < arr2[0].size(); i++) {
        for (int n = 0; n < arr2.size(); n++) {
            nums[i][n] = arr2[n][i];
        }
    }


    for (int i = 0; i < arr1.size(); i++) {
        for (int n = 0; n < arr2[0].size(); n++) {
            int ans = mul(arr1[i], nums[n]);
            answer[i].push_back(ans);
        }
    }

    return answer;
}
