using namespace std;

long long solution(int w,int h) {
    long long answer = 0;
    long long temp = 0;
    
    for(int x = 0; x < h; x++) {
        temp = (long long)(w * x) / h;
        answer += temp;
    }
    answer *= 2;
    return answer;
}