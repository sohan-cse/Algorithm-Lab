#include<bits/stdc++.h>
using namespace std;

int Knapsack(vector<pair<int,int>>&Items,int W){
    int sum=0;
    vector<int>dp(W+1,0);
    for(int i=0;i<Items.size();i++){
        for(int w=W;w>=Items[i].second;w--){
            dp[w]=max(dp[w],Items[i].first+dp[w-Items[i].second]);
        }
    }
    return dp[W];
}

int main(){
    int n,W;
    int val,wt;
    vector<pair<int,int>>Items;
    cout<<"Enter number of element : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter item "<<i+1<<" value : ";
        cin>>val;
        cout<<"Enter item "<<i+1<<" weight : ";
        cin>>wt;
        Items.emplace_back(val,wt);
    }
    cout<<"\nEnter knapsack capacity : ";
    cin>>W;
    cout<<Knapsack(Items,W);

}