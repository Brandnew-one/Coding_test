//BOJ 14501(퇴사)
//백트랙킹,dfs 풀이에 확신이 안섬 -> 다시 풀어볼것
#include <iostream>
#include <utility>
using namespace std;

int N,answer,sum;
bool flag=false;//백트랙킹이 끝났음을 알리는 flag
pair<int,int>arr[17];

void func(int cnt){
    if(flag){
        if(sum>=answer)answer=sum;
        flag=false;
        return;
    }
    for(int i=cnt; i<=N; i++){
        if(i+arr[i].first-1>N){
            flag=true;
            func(0);//다음 func으로 들어가서 return 되도록 0 설정
        }
        else if(i+arr[i].first-1==N){
            flag=true;
            sum+=arr[i].second;
            func(i+arr[i].first);
            sum-=arr[i].second;
        }
        else{
            sum+=arr[i].second;
            func(i+arr[i].first);
            sum-=arr[i].second;
        }
    }
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>arr[i].first>>arr[i].second;
    }
    func(1);
    cout<<answer;

    return 0;
}