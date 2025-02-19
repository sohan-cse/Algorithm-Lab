#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> item1,pair<int,int> item2){
    return item1.first/item1.second > item2.first/item2.second;
}

double Fracktional_Knapsack(vector<pair<int,int>>&Items,double capacity){
    sort(Items.begin(),Items.end(),cmp);
    double sum=0;
    for(auto item: Items){
        if(capacity==0)return sum;
        if(capacity>=item.second){
            sum+=item.first;
            capacity-=item.second;
        }else{
            sum+=capacity*((double)item.first/item.second);
            capacity=0;
        }
    }
    return sum;
}

int main(){
    int n;
    double capacity;
    vector<pair<int,int>>Items;
    cout<<"Enter number of items : ";
    cin>>n;
    for(int i=1;i<=n;i++){
        double val,wt;
        cout<<"Enter item "<<i<<" value : ";
        cin>>val;
        cout<<"Enter item "<<i<< " weight : ";
        cin>>wt;
        Items.emplace_back(val,wt);
    }
    cout<<"Enter capacity of the knapsack : ";
    cin>>capacity;
    cout<<"Total value : "<<Fracktional_Knapsack(Items,capacity);
    return 0;
}