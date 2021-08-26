//BOJ 20055(컨베이어 벨트 위의 로봇)
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int,bool>>c; //해당 벨트의 내구도, 로봇의 유무
int n, k, down_pos, up_pos, answer=1;

//종료조건 판단
bool isover(){
    int cnt=0;
    for(int i=0; i<2*n; i++){
        if(c[i].first==0)cnt++;
    }
    if(cnt>=k)return true;
    else return false;
}

//컨베이어 회전 구현
void rotate_c(){
    pair<int,bool>temp=c[2*n-1];
    c.pop_back();
    c.insert(c.begin(),temp);
    if(c[down_pos].second==true)c[down_pos].second=false;
}

//로보트 회전 구현 + 회전 후 올리는 위치에 로보트 올리기
void rotate_r(){
    for(int i=n-2; i>=0; i--){
        if(c[i].second==true){
            //컨베이어 회전 방향으로 로보트가 존재하지 않고, 내구도가 0보다 큰 경우 이동
            if(c[i+1].first>=1 && !c[i+1].second){
                c[i+1].first-=1;
                c[i+1].second=1;
                c[i].second=0;
                //만약 로보트가 이동한 위치가 내리는 위치면 바로 내려준다.
                if(i+1==down_pos){
                    c[down_pos].second=false;
                }
            }
        }
    }
    if(c[up_pos].first>=1){
        c[up_pos].first-=1;
        c[up_pos].second=1;
    }
}

void func(){
    while(1){
        rotate_c();
        rotate_r();
        if(isover())break;
        answer++;
    }
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k;
    for(int i=0; i<2*n; i++){
        int num;
        cin>>num;
        c.push_back({num,0});
    }
    //올리는 위치, 내리는 위치의 인덱스 설정
    up_pos=0;
    down_pos=n-1;

    func();
    cout<<answer;

    return 0;
}