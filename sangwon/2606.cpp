//BOJ 2606(바이러스)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int>adj[102];
bool vis[102];
int n,m,cnt;

void bfs(){
    
    queue<int>Q;
    Q.push(1);
    vis[1]=1;

    while(!Q.empty()){
        cnt++;
        int cur=Q.front();
        Q.pop();
        for(int i=0; i<adj[cur].size(); i++){
            int next=adj[cur][i];
            if(vis[next])continue;
            Q.push(next);
            vis[next]=1;
        }
    }
}

int main(void){

    cin>>n;
    cin>>m;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //1번에은 제외
    bfs();
    cout<<cnt-1;

    return 0;
}