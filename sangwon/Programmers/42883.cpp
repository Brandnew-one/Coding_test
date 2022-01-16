//프로그래머스 [큰 수 만들기]
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {

    string answer = number;

    while(k > 0) {
        int min_index = -1, index = -1 ,min = 10;
        bool flag = true;
        for(int j = 0; j < answer.size(); j++) {
            if(answer[j] - '0' < min) {
                min = answer[j] - '0';
                min_index = j;
            }
            if(j == answer.size() - 1)continue;
            if(answer[j] < answer[j + 1]) {
                index = j;
                flag = false;
                break;
            }
        }
        if(flag) answer.erase(answer.begin() + min_index);
        else answer.erase(answer.begin() + index);
        k--;
    }

    return answer;
}