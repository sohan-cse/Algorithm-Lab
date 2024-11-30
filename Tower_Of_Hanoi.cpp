#include<bits/stdc++.h>
using namespace std;
int i=0;
void TOH(int n,int A, int B, int C){
    if(!n)return;
    TOH(n-1,A,C,B);
    cout<<"Step-"<<++i<<" : "<<A<<"------>"<<C<<endl;
    TOH(n-1,B,A,C);
}

int main(){
    int n;
    cout<<"Enter number of plate : ";
    cin>>n;
    TOH(n,1,2,3);

    return 0;
}