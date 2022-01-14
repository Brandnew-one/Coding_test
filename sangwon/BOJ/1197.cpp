//BOJ 1197(최소 스패닝 트리)
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
using ti3 = tuple<int,int,int>;// {cost, v1, v2}

int v,e;
long long answer;
vector<pair<int,int>>adj[10002];//{cost, 연결노드}
bool check[10002];//최소 신장트리에 존재하는 노드들

void prim(){
    
    int cnt=0;
    priority_queue< ti3, vector<ti3>, greater<ti3> >PQ;//최소힙
    //처음에는 임의의 노드를 선택하면 되니까 1번 노드를 선택하도록 설정
    //1번 노드와 연결된 간선들을 모두 힙에 저장한다.
    for(int i=0; i<adj[1].size(); i++)
        PQ.push({adj[1][i].first, 1, adj[1][i].second});
    check[1]=true;

    while(1){
        int cost,v1,v2;
        tie(cost,v1,v2)=PQ.top();
        PQ.pop();//최소 cost를 가지는 간선을 pop한다.
        //만약 현재 간선이 최소신장트리에 포함된 두 정점을 연결하면 skip
        if(check[v2])continue;
        //cout<<cost<<' '<<v1<<' '<<v2<<'\n';
        answer+=cost;
        check[v2]=1;//최소신장트리에 추가
        cnt++;
        if(cnt==v-1)break;
        //최소신장트리에 연결된 간선중 최소신장 트리에 포함되지 않는 정점을 연결하는 모든 간선을 힙에 추가한다.
        for(int i=0; i<adj[v2].size(); i++){
            if(!check[adj[v2][i].second])
                PQ.push({adj[v2][i].first, v2, adj[v2][i].second});
        }
    }
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>v>>e;
    for(int i=0; i<e; i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        adj[u].push_back({cost,v});
        adj[v].push_back({cost,u});
    }

    prim();
    cout<<answer;

    return 0;
}

