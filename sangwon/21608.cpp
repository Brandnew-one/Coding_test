//BOJ 21608(상어 초등학교)
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int n,answer;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
int prefer[404][4];
int board[22][22];

//인접한 칸에 좋아하는 학생수, 인접한 칸에 비어있는 칸, {행,열} 를 문제의 조건에 맞게 정렬하기 위한 compare 함수
bool compare(pair<int,pair<int,pair<int,int>>>v1, pair<int,pair<int,pair<int,int>>>v2){
    if(v1.first == v2.first){
        if(v1.second.first == v2.second.first){
            if(v1.second.second.first == v2.second.second.first){
                return v1.second.second.second < v2.second.second.second;
            }
            return v1.second.second.first < v2.second.second.first;
        }
        else return v1.second.first > v2.second.first;
    }
    else return v1.first > v2.first;
}

void student_position(int num){
    //인접한 칸에 좋아하는 학생수, 인접한 칸에 비어있는 칸, {행,열} 순서로 저장
    vector<pair<int,pair<int,pair<int,int>>>>v;
    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++){
            if(board[y][x]!=0)continue;
            int first=0,second=0;
            //인접한 영역을 돌면서 좋아하는 학생수, 비어있는 칸의 개수를 센다.
            for(int dir=0; dir<4; dir++){
                int ny=y+dy[dir];
                int nx=x+dx[dir];
                if(ny<0 || ny>=n || nx<0 || nx>=n)continue;
                if(board[ny][nx]==0)second++;
                else{
                    for(int i=0; i<4; i++){
                        int prefer_student=prefer[num][i];
                        if(board[ny][nx]==prefer_student)first++;
                    }
                }
            }
            v.push_back({first,{second,{y,x}}});
        }
    }
    sort(v.begin(),v.end(),compare);
    int y=v[0].second.second.first;
    int x=v[0].second.second.second;
    board[y][x]=num;//조건에 맞는 위치에 학생을 배치한다.
}

//학생들이 모두 앉았을때 점수를 구하기 위한 함수
void make_answer(){
    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++){
            int num=board[y][x];
            int cnt=0;
            for(int dir=0; dir<4; dir++){
                int ny=y+dy[dir];
                int nx=x+dx[dir];
                if(ny<0 || ny>=n || nx<0 || nx>=n)continue;
                for(int i=0; i<4; i++){
                    if(board[ny][nx]==prefer[num][i])cnt++;
                }
            }
            if(cnt==0)continue;
            else if(cnt==1)answer+=1;
            else if(cnt==2)answer+=10;
            else if(cnt==3)answer+=100;
            else answer+=1000;
        }
    }
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=1; i<=n*n; i++){
        int num;
        cin>>num;
        for(int j=0; j<4; j++){
            cin>>prefer[num][j];
        }
        student_position(num);
    }
    make_answer();
    cout<<answer;

    return 0;
}