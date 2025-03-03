#include<bits/stdc++.h>
using namespace std;

const int INF=1e5;
int n;

vector<vector<int>>dist;
vector<vector<int>>dp;

int TSP(int mask,int pos){
    if((1<<n)-1==mask)return dist[pos][0];

    if(dp[mask][pos]!=-1)return dp[mask][pos];
    int ans=INT_MAX;

    for(int city=0;city<n;city++){
        if(!(mask&(1<<city))){
            int newAns=dist[pos][city]+TSP(mask|(1<<city),city);
            ans=min(ans,newAns);
        }
    }

    return dp[mask][pos]=ans;
}

int main(){

    cout<<"Enter number of vertices : ";
    cin>>n;

    dist.resize(n,vector<int>(n));
    dp.resize(1<<n,vector<int>(n,-1));

    for(int i=0;i<n;i++)dist[i][i]=0;

    cout<<"Enter edges (-1 for exit ) \n";
    while(true){
        int u,v,wt;
        cout<<"source : ";
        cin>>u;
        if(u==-1)break;
        cout<<"Destination , weight : ";
        cin>>v>>wt;
        dist[u][v]=wt;
        dist[v][u]=wt;
    }

    cout<<"Total cost : "<<TSP(1,0)<<endl;
}
