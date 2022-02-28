//프로그래머스 [완주하지 못한 선수]
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// 단순히 2중 for 문을 통해서 검색하면 O(10^10)
string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i = 0; i < completion.size(); i++) {
        if(participant[i] != completion[i]) {
            return participant[i];
        }
    }
    return participant[participant.size() - 1];
}