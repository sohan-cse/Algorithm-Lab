#include<bits/stdc++.h>
using namespace std;

void maxHeap(vector<int>&arr,int i,int Size){
    if(i<0)return;
    int l=2*i+1;
    int r=2*i+2;
    int largest;

    if(l<Size&& arr[i]<arr[l])largest=l;
    else largest=i;
    if(r<Size&& arr[largest]<arr[r])largest=r;

    if(largest!=i){
        swap(arr[i],arr[largest]);
        maxHeap(arr,largest,Size);
    }
}

void heapify(vector<int>&arr){
    for(int i=(arr.size()/2)-1;i>=0;i--){
        maxHeap(arr,i,arr.size());
    }
}

void heapSort(vector<int>&arr){
    for(int i=arr.size()-1;i>0;i--){
        swap(arr[i],arr[0]);
        maxHeap(arr,0,i);
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
        heapify(arr);
    }


    cout<<"Before sorting : ";
    for(auto ele : arr)cout<<ele<<"  ";
    
    heapSort(arr);

    cout<<"\nAfter sorting : ";
    for(auto ele : arr)cout<<ele<<"  ";

    return 0;
}
