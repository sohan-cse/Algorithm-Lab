#include<bits/stdc++.h>
using namespace std;
int i=0;
void TOH(int n,char source, char Auxiliary, char destination){
    if(!n)return;
    TOH(n-1,source,destination,Auxiliary);
    cout<<"Step-"<<++i<<" : Move disk "<<n<<" from "<<source<<"------>"<<destination<<endl;
    TOH(n-1,Auxiliary,source,destination);
}

int main(){
    int n;
    cout<<"Enter number of plate : ";
    cin>>n;
    TOH(n,'A','B','C');

    return 0;
}