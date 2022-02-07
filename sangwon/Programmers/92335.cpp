// 프로그래머스 [k진수에서 소수 개수 구하기] - TC 1번 왜 long long 하나 차이에서 시간초과 오류가 날까?
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

string kNumber = "";

//소수 판별
bool isPrime(long long num){
    if(num == 1) return false;
    for(long long i = 2; i * i <= num; i++){
        if(num % i == 0) return false;
    }
    return true;
}

//k진수 변환
void Knumber(int n, int k) {
    while(1) {
        kNumber += to_string(n % k);  
        n /= k;
        if(n == 0) break;
    }
    reverse(kNumber.begin(), kNumber.end());
}

int solution(int n, int k) {
    int answer = 0;
    Knumber(n, k);

    // cout << kNumber << '\n';

    string temp = "";
    for(int i = 0; i < kNumber.size(); i++) {
        if(kNumber[i] == '0') {
            if(temp.empty())continue;
            else {
                long long t = stoll(temp);
                // cout << t << '\n';
                if(isPrime(t)) answer++;
            }
            temp = "";
        }
        else {
            temp += kNumber[i];
        }
    }
    // 마지막에 0을 만나지 않은 경우 처리
    if(!temp.empty()) {
        long long t = stoll(temp);
        // cout << t << '\n';
        if(isPrime(t)) answer++;
    }

    return answer;
}
