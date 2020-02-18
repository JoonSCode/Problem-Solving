//Main idea: 완전 
#include <string>
#include <vector>
#include <utility>

using namespace std;

pair<int,int> compare(string& str1, string& str2){
    int a = 0;
    int b = 0;
    for(int i = 0 ; i < 3; i++){
        if(str1[i] == str2[i])
            a++;
        else{
            for(int n = 0; n < 3; n++){
                if(str1[i] == str2[n]){
                    b++;
                    break;
                }
            }
        }
    }
    return {a,b};
}

bool check(vector<vector<int>>& ball, string& str){
    for(int i = 0; i < ball.size(); i++){
        string ball_str = to_string(ball[i][0]);
        pair<int,int> test = compare(str, ball_str);
        if(test.first != ball[i][1] || test.second != ball[i][2])
            return false;
    }
    return true;
}


int solution(vector<vector<int>> baseball) {
    int answer = 0;
    vector<string>ans;
    for(int i = 1; i <= 9; i++){
        for(int n = 1; n <= 9; n++){
            if(i == n)
                continue;
            for(int k = 1; k <= 9; k++){
                if(i == k || n == k)
                    continue;
                int tmp = i*100+n*10+k;
                ans.push_back(to_string(tmp));
            }
        }
    }
    for(string str : ans){
        if(check(baseball, str))
            answer++;
    }
    
    
    return answer;
}
