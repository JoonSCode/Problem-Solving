//Main idea: map을 이용한 캐시 시뮬레이션
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if(cacheSize == 0 )
        return cities.size() * 5;
    for(string& str: cities)
        transform(str.begin(), str.end(), str.begin(), ::tolower);//소문자로 통일한다.
    unordered_map<string,int> cache;
    for(int i = 0; i < cities.size(); i++){
        string& str = cities[i];
        if(cache.find(str) != cache.end()){
            cache.find(str)->second = i;
            answer++;
            continue;
        }
        if(cache.size() == cacheSize){
            int min_val = 987654321;
            string min_str;
            for(pair<string, int> a: cache){
                if(a.second > min_val) continue;
                min_val = a.second;
                min_str = a.first;
            }
            cache.erase(min_str);
        }
        cache.insert({str,i});
        answer+=5;
    }
    return answer;
}
