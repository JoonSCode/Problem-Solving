//Main idea: 문자열 자르기, 안전정렬(기본 sort는 안전 정렬이 아님!)
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

pair<string, int> check(string& str) {//분류 함수
    int start = -1;
    int end = -1;
    for (int i = 0; i < str.size(); i++) {
        char a = str[i];
        if (a >= '0' && a <= '9') {
            if (start == -1)
                start = i;
        }
        else if (start != -1) {
            end = i;
            break;
        }
    }
    string head = str.substr(0, start);
    string num = str.substr(start, end - start);


    for (int i = 0; i < head.size(); i++) {
        head[i] = tolower(head[i]);
    }
    return { head ,atoi(num.c_str()) };
}

bool compare(string& a, string& b) {
    pair<string, int> ap = check(a);
    pair<string, int> bp = check(b);


    if (ap.first > bp.first)
        return false;
    if (ap.first == bp.first) {
        if (ap.second > bp.second)
            return false;
    }
    return true;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
 
    for (int i = 1; i < files.size(); i++) {//삽입 정렬을 사용
        string tmp = files[i];
        for (int n = i - 1; n >=0; n--) {
            if(!compare(files[n], tmp)){
                files[n+1] = files[n];
                if(n == 0)
                    files[n] = tmp;
            }
            else{                    
                files[n+1] = tmp;
                break;
            }
        }
    }
    return files;
}
