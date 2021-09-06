//프로그래머스 모의고사 
//[문제링크] https://programmers.co.kr/learn/courses/30/lessons/42840
#include <string>
#include <vector>

using namespace std;

int c1, c2, c3; //각각 맞은 문제 count
int c[3];
int a1[5] = {1, 2 ,3 ,4 ,5};
int a2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int a3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

void count_answer(vector <int> answers){
    int size = answers.size();
    for(int i =0 ; i < size; i++){
        if(a1[i%5] == answers[i])c1++;
        if(a2[i%8] == answers[i])c2++;
        if(a3[i%10] == answers[i])c3++;
    }
    
    c[0] = c1;
    c[1] = c2;
    c[2] = c3;
}

vector<int> solution(vector<int> answers) {
    
    count_answer(answers);
    vector<int> answer;
    
    int max_value = 0;
    for(int i =0; i < 3; i++){
        if(c[i] >= max_value)max_value = c[i];
    }
    
    for(int i = 0; i < 3; i++){
        if(c[i] == max_value){
            answer.push_back(i+1);
        }
    }
    
    return answer;
}