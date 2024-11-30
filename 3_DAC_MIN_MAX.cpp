#include<bits/stdc++.h>
using namespace std;
//int ct=0;

pair<int,int>findMinMax(vector<int>&arr,int low,int high){
    //for 1 element
    //ct++;
    if(low==high){
        return {arr[low],arr[high]};
    }

    //for 2 element
    if(low==high-1){
        if(arr[low]<arr[high]){
            return {arr[low],arr[high]};
        }else{
            return {arr[high],arr[low]};
        }
    }

    //reccursive call
    int mid=low+(high-low)/2;
    
    pair<int,int>leftArr=findMinMax(arr,low,mid);
    pair<int,int>rightArr=findMinMax(arr,mid+1,high);

    int finalMin=min(leftArr.first,rightArr.first);
    int finalMax=max(leftArr.second,rightArr.second);

    return {finalMin,finalMax};
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto&ele:arr){
        cin>>ele;
    }

    pair<int,int>result=findMinMax(arr,0,n-1);
    cout<<"Minimum : "<<result.first<<endl;
    cout<<"Maximum : "<<result.second<<endl;
    //cout<<ct<<endl;

    return 0;
}