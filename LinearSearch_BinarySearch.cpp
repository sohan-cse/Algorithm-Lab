#include<bits/stdc++.h>
using namespace std;
int linearSearch(vector<string>arr,string target){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}
int binarySearch(vector<string>arr,string target){
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
    int n,i=1;
    cin>>n;
    vector<string>arr(n);
    for(auto&ele:arr){
        ele="u"+to_string(i);
        i++;
    }
    string target;
    cin>>target;
    auto start=chrono::high_resolution_clock::now();
    int linearResult=linearSearch(arr,target);
    auto end=chrono::high_resolution_clock::now();
    cout<<"Linear search time :"<<chrono::duration_cast<chrono::microseconds>(end-start).count()<<" microseconds"<<endl;
    
    start=chrono::high_resolution_clock::now();
    int binaryResult=binarySearch(arr,target);
    //sort(arr.begin(),arr.end());
     end=chrono::high_resolution_clock::now();
    cout<<"Binary search time :"<<chrono::duration_cast<chrono::microseconds>(end-start).count()<<" microseconds"<<endl;
    return 0;
}