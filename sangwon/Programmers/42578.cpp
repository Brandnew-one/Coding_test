// [프로그래머스]위장

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> map;

void makeHashMap(vector<vector<string>> clothes) {
    for(int i = 0; i < clothes.size(); i++) {
        if(map.find(clothes[i][1]) == map.end()) {
            map[clothes[i][1]] = 1;
        } else {
            map[clothes[i][1]] += 1;
        }
    }
    //TEST
    for(auto e : map) {
        cout << e.first << " " << e.second << '\n';
    }
}

int solution(vector<vector<string>> clothes) {
    makeHashMap(clothes);
    int answer = 0;
    if(map.size() == 1) {
        answer = map.begin() -> second;
    } else {
        answer = 1;
        for(auto e : map) {
            answer *= (e.second + 1);
        }
        answer -= 1;
    }
    return answer;
}