//BOJ 5567(결혼식)
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int n,m,answer;
vector<int>adj[502];
int vis[502];

void bfs(){
    queue<int>Q;
    Q.push(1);
    vis[1]=1;
    while(!Q.empty()){
        int cur=Q.front();
        Q.pop();
        for(int i=0; i<adj[cur].size();i++){
            int next=adj[cur][i];
            if(vis[next]!=0)continue;
            Q.push(next);
            vis[next]=vis[cur]+1;
        }
    }
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs();
    for(int i=1; i<=n; i++){
        if(vis[i]==2 || vis[i]==3)answer++;
    }
    cout<<answer;
    return 0;
}