#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>arr,int target){
    int lb=0;
    int ub=arr.size()-1;
    while(lb<=ub){
        int mid=lb+(ub-lb)/2;
        if(target==arr[mid]){
            return mid;
        }
        if(target<arr[mid]){
            ub=mid-1;
        }else{
            lb=mid+1;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto&ele:arr){
        cin>>ele;
    }
    int target;
    cin>>target;
    cout<<binarySearch(arr,target)<<endl;
    cout<<"Time complexity for best_case: O(1)"<<endl;
    cout<<"Time complexity for average/worst case: O(log(n))"<<endl;
    cout<<"Space complexity for iterative implementation: O(1)"<<endl;
    cout<<"Space complexity for recursive implementation: O(log(n))"<<endl;
    return 0;
}