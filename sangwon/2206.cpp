//BOJ 2206(벽 부수고 이동하기)
//다시 풀어볼 문제!!
#include <iostream>
#include <string>
#include <queue>
#include <utility>
using namespace std;

char board[1002][1002];
int dis[1002][1002][2];
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
int n,m;

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    string s;
    for(int y=0; y<n; y++){
        cin>>s;
        for(int x=0; x<m; x++){
            board[y][x]=s[x];
        }
    }
    //벽을 꺠고 왔는지를 저장해야 하기 때문에 3차원으로 선언
    queue<pair<pair<int,int>,int>>Q;
    Q.push({{0,0},0});
    dis[0][0][0]=1;
    while(!Q.empty()){
        pair<pair<int,int>,int>cur=Q.front();
        Q.pop();
        for(int dir=0; dir<4; dir++){
            int ny=cur.first.first+dy[dir];
            int nx=cur.first.second+dx[dir];
            if(ny<0 || ny>=n || nx<0 || nx>=m)continue;
            //if(dis[ny][nx][0]!=0 || dis[ny][nx][1]!=0)continue;//이미 방문한 좌표라면 skip
            if(dis[ny][nx][cur.second]!=0)continue;
            //벽을 만나는 경우
            if(board[ny][nx]=='1'){
                if(cur.second==1)continue;//이미 벽을 꺠고 온 case
                else{
                    Q.push({{ny,nx},1});
                    dis[ny][nx][1]=dis[cur.first.first][cur.first.second][cur.second]+1;
                }
            }
            //벽을 만나지 않는 경우
            else{
                Q.push({{ny,nx},cur.second});
                dis[ny][nx][cur.second]=dis[cur.first.first][cur.first.second][cur.second]+1;
            }
        }
    }
    //시작점도 포함된다.
    if(dis[n-1][m-1][0]==0 &&dis[n-1][m-1][1]==0)cout<<-1;
    else if(dis[n-1][m-1][0]==0 &&dis[n-1][m-1][1]!=0)cout<<dis[n-1][m-1][1];
    else if(dis[n-1][m-1][0]!=0 &&dis[n-1][m-1][1]==0)cout<<dis[n-1][m-1][0];
    else{
        if(dis[n-1][m-1][0]>=dis[n-1][m-1][1])cout<<dis[n-1][m-1][1];
        else cout<<dis[n-1][m-1][0];
    }
    /*
    cout<<'\n';
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            cout<<board[y][x]<<' ';
        }
        cout<<'\n';
    }

    cout<<'\n';
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            cout<<dis[y][x][0]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            cout<<dis[y][x][1]<<' ';
        }
        cout<<'\n';
    }
    */
    return 0;
}