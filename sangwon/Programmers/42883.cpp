//프로그래머스 [큰 수 만들기]
// TC10 시간초과...
#include <string>
#include <vector>

using namespace std;

vector<int> intNumber;

void char_to_int(string number) {
    for(int i = 0; i < number.size(); i++) {
        int numbers = number[i] - '0';
        intNumber.push_back(numbers);
    }
}


// 현재 인덱스보다 다음 인덱스의 수가 크다면 현재 인덱스를 버린다. (TC10 시간초과)
void make_max2(string number, int k) {
    for(int i = 0; i < k; i++) {
        int min_index = -1, index = -1 ,min = 10;
        bool flag = true;
        for(int j = 0; j < intNumber.size(); j++) {
            if(intNumber[j] < min) {
                min = intNumber[j];
                min_index = j;
            }
            if(j == intNumber.size() - 1)continue;
            if(intNumber[j] < intNumber[j + 1]) {
                index = j;
                flag = false;
                break;
            }
        }
        if(flag) intNumber.erase(intNumber.begin() + min_index);
        else intNumber.erase(intNumber.begin() + index);
    }
}

string solution(string number, int k) {
    
    char_to_int(number);
    make_max2(number, k);
    
    string answer = "";
    for(int i = 0; i < intNumber.size(); i++) {
        answer.push_back(intNumber[i] + '0');
    }
    
    return answer;
}