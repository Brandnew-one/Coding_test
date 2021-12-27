//프로그래머스 [수식최대화] - 다시 풀어보기
// operators 실수해서 시간 날려먹음
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//6가지 경우의 수(+,-,*) 설정해주고 (1. 미리만들거나 2. 순열로 만들거나)
vector <string> operators = {"*+-", "*-+", "+*-", "+-*", "-*+", "-+*"};
vector<long long> numbers; //숫자를 담을 벡터
vector<char> op; //연산자를 담을 벡터

long long answer = 0;

bool isOp(char s) {
    if(s == '+' || s == '-' || s == '*') return true;
    else return false;
}

long long cal(long long a, long long b, char op) {
    if(op == '+') return a + b;
    else if (op == '*') return a * b;
    else return a - b;
}

void seperateNum(string expression) {
    int temp = 0;
    //한자리수가 아닐경우를 대비
    for(int i = 0; i < expression.size(); ) {
        for(int j = i; j < expression.size(); j++) {
            if(!isOp(expression[j])) {
                if(temp != 0) { //한자리수 숫자가 아닌경우
                    temp *= 10;
                    temp += (expression[j] - '0');
                }
                else temp = (expression[j] - '0');
                i = j + 1;
            }
            //연산자를 만난 경우, 벡터에 각각의 값을 넣어준다.
            else {
                numbers.push_back(temp);
                op.push_back(expression[j]);
                i = j + 1;
                temp = 0;
                break;
            }
        }
    }
    numbers.push_back(temp); //마지막 숫자 push
}

void make_sum(int k) {
    long long temp = 0;
    for(int j = 0; j < 3; j++) {
        int index = 0;
        for(; index < op.size(); index++) {
            if(op[index] == operators[k][j]) {
                temp = cal(numbers[index], numbers[index + 1], op[index]);
                op.erase(op.begin() + index);
                numbers[index] = temp;
                numbers.erase(numbers.begin() + index + 1);
                index = -1;
            }
        }
    }
    temp = numbers[0];
    if(temp < 0) temp *= -1;
    if(temp >= answer) answer = temp;
    numbers.erase(numbers.begin());
}

long long solution(string expression) {
    for(int k = 0; k < 6; k++) {
        seperateNum(expression);
        make_sum(k);
    }
    return answer;
}