//Main idea: 소수 찾는 방법(에라토스테네스의 체), 완전탐색, 만들 수 있는지 검사 
#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool check(vector<int> arr, int& num){
    string str = to_string(num);
    for(char a: str){
        if(arr[a-'0'] > 0)
            arr[a-'0']--;
        else
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    
    int sz = numbers.size();
    vector<int> prime_arr(10000000,1);
    
    
    vector <int> arr(10,0);
    
    for(char i : numbers)
        arr[i-'0'] ++; 
    sz = pow(10,sz);
    for(int i = 2; i < sz; i++){
        if(prime_arr[i] == 1){//소수인 경우
            int tmp = 2;
            while(tmp*i < sz){
                prime_arr[tmp*i] = 0;
                tmp++;
            }
            if(check(arr,i))
                answer++;
        }
    }
    return answer;
}
