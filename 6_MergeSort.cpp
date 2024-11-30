#include<bits/stdc++.h>
using namespace std;
void Merge(int arr[],int lb,int mid,int ub){
    int n1=mid-lb+1;
    int n2=ub-mid;
    int leftArr[n1];
    int rightArr[n2];

    for(int i=0;i<n1;i++){
        leftArr[i]=arr[lb+i];
    }
    for(int i=0;i<n2;i++){
        rightArr[i]=arr[mid+1+i];
    }

    int i=0,j=0,k=lb;

    while(i<n1 && j<n2){
        if(leftArr[i]<rightArr[j]){
            arr[k]=leftArr[i];
            i++;
            k++;
        }else{
            arr[k]=rightArr[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        arr[k]=leftArr[i];
            i++;
            k++;
    }
    while(j<n2){
        arr[k]=rightArr[j];
            j++;
            k++;
    }
}
void MergeSort(int arr[],int lb,int ub){
    if(lb==ub)return;
    int mid=lb+(ub-lb)/2;
    MergeSort(arr, lb, mid);
    MergeSort(arr, mid+1, ub);
    Merge(arr,lb,mid,ub);
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
    MergeSort(arr,0,n-1);
    cout<<"\nAfter sorting : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}