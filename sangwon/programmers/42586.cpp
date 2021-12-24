#include <string>
#include <vector>

using namespace std;

bool isFinished(vector<int> progresses, int size) {
    for(int i = 0; i < size; i++) {
        if(progresses[i] < 100) return false;
    }
    return true;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int complete_index = 0;
    int end_index = progresses.size();
    
    while(1) {
        if(isFinished(progresses, end_index))break;
        // speeds 만큼을 더해줌
        for(int i = complete_index; i < end_index; i++) {
            progresses[i] += speeds[i];
        }
        // 만약 오늘 작업 완료된게 있다면 answer에 추가해줌
        int temp = 0;
        for(int i = complete_index; i < end_index; i++) {
            if(progresses[i] < 100) {
                break;
            }
            else {
                temp++;
                complete_index++;
            }
        }
        if(temp != 0) answer.push_back(temp);
    }
    return answer;
}