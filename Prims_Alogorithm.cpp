#include<bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int>>path;

int prims(vector<vector<pair<int,int>>>&adjList,int src){
    int n=adjList.size();
    vector<bool>vis(n,false);
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;//min heap
    pq.emplace(0,src,-1);
    int sum=0;
    while(!pq.empty()){

        int wt=get<0>(pq.top());
        int node=get<1>(pq.top());
        int prev=get<2>(pq.top());
        pq.pop();

        if(vis[node])continue;
        vis[node]=true;

        if(prev!=-1){
            path.emplace_back(prev,node,wt);
        }
        
        sum+=wt;

        for(auto ele :adjList[node]){
            int adjnode=ele.first;
            int adjwet=ele.second;
            if(!vis[adjnode]){
                pq.emplace(adjwet,adjnode,node);
            }
        }
    }
    return sum;
}

int main(){
    int n,e;
    cout<<"Enter number of vertices and edges : ";
    cin>>n>>e;
    vector<vector<pair<int,int>>>adjList(n);
    for(int i=0;i<e;i++){
        int u,v,wt;
        cout<<"source,destination ,weight "<<endl;
        cin>>u>>v>>wt;
        adjList[u].emplace_back(v,wt);
        adjList[v].emplace_back(u,wt);
    }
    cout<<"Enter starting node : ";
    int src;
    cin>>src;
    cout<<"Min cost : "<<prims(adjList,src)<<endl;

    cout<<"source--destination--weight "<<endl;
    for(auto ele: path){
        cout<<get<0>(ele)<<"  "<<get<1>(ele)<<"  "<<get<2>(ele)<<"  "<<endl;
    }
    return 0;
}
