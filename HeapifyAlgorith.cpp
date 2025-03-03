#include<bits/stdc++.h>
using namespace std;

void heapify_max(vector<int>&arr,int i){

    int l=2*i+1;
    int r=2*i+2;
    int large;

    if(l<arr.size()&&arr[i]<arr[l])large=l;
    else large=i;
    if(r<arr.size()&&arr[large]<arr[r])large=r;

    if(i!=large){
        swap(arr[i],arr[large]);
        heapify_max(arr,large);
    }

}
void heapify_min(vector<int>&arr,int i){

    int l=2*i+1;
    int r=2*i+2;
    int small;

    if(l<arr.size()&&arr[i]>arr[l])small=l;
    else small=i;
    if(r<arr.size()&&arr[small]>arr[r])small=r;

    if(i!=small){
        swap(arr[i],arr[small]);
        heapify_min(arr,small);
    }

}

int main(){
    vector<int>arr;
    while(true){
        cout<<"Enter element (-1 for exit) : ";
        int ele;
        cin>>ele;
        if(ele==-1)break;
        arr.push_back(ele);
    }

    cout<<"Max heap : ";
    for(int i=arr.size()/2-1;i>=0;--i)
    heapify_max(arr,i);
    for(auto ele:arr)cout<<ele<< " ";

    cout<<"\nMin heap : ";
    for(int i=arr.size()/2-1;i>=0;--i)
    heapify_min(arr,i);
    for(auto ele:arr)cout<<ele<< " ";

    return 0;
}
