//BOJ 4963(섬의개수)
#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int dy[8]={-1,1,0,0,-1,-1,1,1};
int dx[8]={0,0,-1,1,1,-1,-1,1};
int board[52][52];
bool vis[52][52];
int cnt_island;
int w,h;

int main(void){

    while(1){
        cin>>w>>h;
        if(w==0 && h==0)break;
        cnt_island=0;
        //vis 초기화
        for(int y=0; y<h; y++)
            for(int x=0; x<w; x++)vis[y][x]=0;
        for(int y=0; y<h; y++)
            for(int x=0; x<w; x++)cin>>board[y][x];

        queue<pair<int,int>>Q;
        for(int y=0; y<h; y++){
            for(int x=0; x<w; x++){
                if(board[y][x]==1 && vis[y][x]==0){
                    Q.push({y,x});
                    vis[y][x]=1;
                    cnt_island++;
                }
                while(!Q.empty()){
                    pair<int,int>cur=Q.front();
                    Q.pop();
                    for(int dir=0; dir<8; dir++){
                        int ny=cur.first+dy[dir];
                        int nx=cur.second+dx[dir];
                        if(ny<0 || ny>=h || nx<0 || nx>=w)continue;
                        if(vis[ny][nx] || board[ny][nx]==0)continue;
                        Q.push({ny,nx});
                        vis[ny][nx]=1;
                    }
                }
            }
        }
        cout<<cnt_island<<'\n';
    }

    return 0;
}