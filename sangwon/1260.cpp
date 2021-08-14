//BOJ 1260(BFS와 DFS)
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int N,M,V;
vector<int>adj[1002];
bool vis[1002];

void bfs(int s){
    queue<int>Q;
    Q.push(s);
    vis[s]=1;
    while(!Q.empty()){
        int cur=Q.front();
        Q.pop();
        cout<<cur<<' ';
        for(int i=0; i<adj[cur].size(); i++){
            int next=adj[cur][i];
            if(vis[next])continue;
            Q.push(next);
            vis[next]=1;
        }
    }
}

void dfs_recur(int cur){
    cout<<cur<<' ';
    for(int i=0; i<adj[cur].size(); i++){
        int next=adj[cur][i];
        if(vis[next])continue;
        vis[next]=1;
        dfs_recur(next);
    }
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M>>V;
    for(int i=0; i<M; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //정점번호가 작은것 부터 우선적으로 방문하게 하기 위해서
    for(int i=1; i<=N; i++){
        sort(adj[i].begin(),adj[i].end());
    }

    vis[V]=1;
    dfs_recur(V);
    fill(vis,vis+1002,0);
    cout<<'\n';
    bfs(V);

    return 0;
}