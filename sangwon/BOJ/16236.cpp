//BOJ 16236(아기상어)
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
int board[22][22];
int vis[22][22];
int n,eat_fish,cnt,shark_size=2;
pair<int,int>shark_pos;

vector<pair<int,pair<int,int>>>eatable_fishes;

void find_fish(){
    //vis 초기화
    for(int y=0;y<n;y++)
        for(int x=0;x<n;x++)vis[y][x]=0;

    queue<pair<int,int>>Q;
    Q.push({shark_pos.first,shark_pos.second});
    vis[shark_pos.first][shark_pos.second]=1;//start

    while(!Q.empty()){
        pair<int,int>cur=Q.front();
        Q.pop();
        for(int dir=0; dir<4; dir++){
            int ny=cur.first+dy[dir];
            int nx=cur.second+dx[dir];
            if(ny<0 || ny>=n || nx<0 || nx>=n)continue;
            if(vis[ny][nx]>0)continue;
            if(board[ny][nx]>shark_size)continue;
            //크기가 같은경우 먹을수는 없지만 해당칸으로 이동할 수는 있음
            else if(board[ny][nx]==shark_size){
                Q.push({ny,nx});
                vis[ny][nx]=vis[cur.first][cur.second]+1;
            }
            else if(board[ny][nx]==0){
                Q.push({ny,nx});
                vis[ny][nx]=vis[cur.first][cur.second]+1;
            }
            //먹을 수 있는 물고기에 도달한 경우
            else{
                int t=vis[cur.first][cur.second];
                vis[ny][nx]=vis[cur.first][cur.second]+1;//방문했음을 표시
                eatable_fishes.push_back({t,{ny,nx}});
                //break;
            }
        }
    }
    /*
    cout<<"///////////////////////////////////////\n";
    cout<<"현재크기: "<<shark_size<<'\n';
    for(int i=0; i<eatable_fishes.size(); i++){
        cout<<"dis: "<<eatable_fishes[i].first<<'\n';
        cout<<"y: "<<eatable_fishes[i].second.first<<'\n';
        cout<<"x: "<<eatable_fishes[i].second.second<<'\n';
    }
    cout<<'\n';
    */
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int y=0; y<n; y++)
        for(int x=0; x<n; x++){
            cin>>board[y][x];
            if(board[y][x]==9){
                shark_pos.first=y;
                shark_pos.second=x;
                board[y][x]=0;
            }
        }

    while(1){
        find_fish();
        if(eatable_fishes.empty())break;
        else{
            sort(eatable_fishes.begin(), eatable_fishes.end());
            cnt+=eatable_fishes[0].first;
            shark_pos.first=eatable_fishes[0].second.first;
            shark_pos.second=eatable_fishes[0].second.second;
            board[shark_pos.first][shark_pos.second]=0;
            eat_fish++;
            if(eat_fish==shark_size){
                eat_fish=0;
                shark_size++;
            }
            eatable_fishes.clear();
        }
    }
    cout<<cnt;

    return 0;
}
