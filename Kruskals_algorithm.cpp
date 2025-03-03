#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;

int parent[N],Size[N];

void Make(int v){

    parent[v]=v;
    Size[v]=1;

}

int Find(int v){

    if(parent[v]==v)return v;
    return parent[v]=Find(parent[v]);//path compression

}

void Union(int u,int v){
    u=Find(u);
    v=Find(v);
    if(u!=v){
        if(Size[u]<Size[v]){
            swap(u,v); 
        }
        parent[v]=u;
        Size[u]+=Size[v];
    }
}

int main(){

    int n,e;
    cout<<"Enter number of vertices and edges : ";
    cin>>n>>e;

    for(int i=0;i<n;i++)Make(i);

    vector<pair<int,pair<int,int>>>edges;

    cout<<"Enter egdes\nsource,destination,weight\n";
    for(int i=0;i<e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.emplace_back(wt,make_pair(u,v));
    }

    sort(edges.begin(),edges.end());

    int totalCost=0;
    for(auto &edge:edges){
        int wt=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;

        if(Find(u)==Find(v))continue;

        Union(u,v);
        cout<<u<<"--"<<v<<"-->"<<wt<<endl;
        totalCost+=wt;
    }

    cout<<"Total cost : "<<totalCost<<endl;
    return 0;
}


