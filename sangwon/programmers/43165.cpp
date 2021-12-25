#include <string>
#include <vector>
#include <iostream>

using namespace std;

int arr[22];
bool isused[22];
int n, m, answer = 0;
int count;

void isAnswer() {
    int temp_sum = 0;
    for(int i = 0; i < count; i++) {
        if(isused[i]) temp_sum += (arr[i] * -1);
        else temp_sum += arr[i];
    }
    if(temp_sum == m) answer++;
    // cout << "temp_sum: " << temp_sum << '\n';
}

void func(int k, int index) {
    if(k == n) {
        isAnswer();
        return;
    }
    for(int i = index; i < count; i++) {
        if(isused[i]) continue;
        isused[i] = true;
        func(k + 1, i + 1);
        isused[i] = false;
    }
}

int solution(vector<int> numbers, int target) {
    count = numbers.size();
    m = target;
    //arr 초기화
    for(int i = 0; i < count; i++) {
        arr[i] = numbers[i];
    }
    // -연산자 몇개 고를지 (조합) (0~count)    
    for(n = 0; n < numbers.size(); n++) {
        for(int i = 0; i < numbers.size(); i++) isused[i] = false;
        func(0, 0);
    }
    
    return answer;
}