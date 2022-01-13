// 프로그래머스 [줄 서는 방법] - 다시 풀어보기!
#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long factorial(int n) {
    long long answer = 1;
    for(int i = 1; i <= n; i++) {
        answer *= i;
    }
    return answer;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> numbers;
    
    //1 ~ n까지 
    for(int i = 1; i <= n; i++) {
        numbers.push_back(i);
    }
    
    for(int i = 1; i < n; i++) {
        long long temp = factorial(n - i);
        long long ref = temp;
        for(int j = 0; j < n; j++) {
            if(temp >= k) {
                answer.push_back(numbers[j]);
                numbers.erase(numbers.begin() + j);
                k -= (j * ref); //핵심
                break;
            }
            temp += ref;
        }
    }
    
    for(int i = 0; i < numbers.size(); i++) {
        answer.push_back(numbers[i]);
    }
    
    // for(int i = 0; i < answer.size(); i++) {
    //     cout << answer[i] << ' ';
    // }
    
    return answer;
}