#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto&ele:arr){
        cin>>ele;
    }
    int minEle=INT_MAX;
    int maxEle=INT_MIN;
    for(int i=0;i<n;i++){
        minEle=min(arr[i],minEle);
        maxEle=max(arr[i],maxEle);
    }
    cout<<"Minimum element : "<<minEle<<endl;
    cout<<"Maximum element : "<<maxEle<<endl;
    cout<<"Time complexity : O(n)"<<endl;
    cout<<"Space complexity : O(1)"<<endl;

    return 0;
}