#include<bits/stdc++.h>
using namespace std;

vector<int>dijkstra(vector<vector<pair<int,int>>>&adjList,int s,int n){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>disArr(n,1e5+10);
    disArr[s]=0;
    pq.emplace(0,s);
    while(!pq.empty()){

        int wt=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        for(auto edge : adjList[node]){
            int adjNode=edge.first;
            int adjWeight=edge.second;
            if(wt+adjWeight<disArr[adjNode]){
                disArr[adjNode]=wt+adjWeight;
                pq.emplace(disArr[adjNode],adjNode);
            }
        }

    }

    return disArr;
}

int main(){
    int n,e;
    cout<<"Enter number of vertices and edges : ";
    cin>>n>>e;
    vector<vector<pair<int,int>>>adjList(n);
    cout<<"Enter source, destination,weight \n";
    for(int i=0;i<e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adjList[u].emplace_back(v,wt);
        adjList[v].emplace_back(u,wt);
    }

    vector<int>distance=dijkstra(adjList,0,n);
    for(int i=0;i<n;i++){
        cout<<0<<"---"<<i<<"-->"<<distance[i]<<endl;
    }

    return 0;
}