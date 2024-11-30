#include<bits/stdc++.h>
using namespace std;
int partitionArray(int arr[], int lb ,int ub){
    int pivot=arr[ub];
    int i=lb;
    for(int j=lb;j<ub;j++){
        if(arr[j]<=pivot){
            swap(arr[j],arr[i]);
            i++;
        }
    }
    swap(arr[ub],arr[i]);
    return i;
}
void QuickSort(int arr[],int lb, int ub){
    if(lb<ub){
        int pi=partitionArray(arr,lb,ub);
        QuickSort(arr,lb,pi-1);
        QuickSort(arr,pi+1,ub);
    }
}
int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Before sorting : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    QuickSort(arr,0,n-1);

    cout<<"\nAfter sorting : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}