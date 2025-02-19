#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
vector<vector<int>>dp(N,vector<int>(N,-1));

int LCS(string &s1,string &s2, int m, int n){
    if(m==0||n==0)return 0;
    if(dp[m][n]!=-1)return dp[m][n];

    if(s1[m-1]==s2[n-1])dp[m][n]= 1+LCS(s1,s2,m-1,n-1);
    else dp[m][n]= max(LCS(s1,s2,m,n-1),LCS(s1,s2,m-1,n));

    return dp[m][n];
}

int main(){

    cout<<"Enter strings : ";
    string s1,s2;
    cin>>s1>>s2;
    int  m=s1.size();
    int n=s2.size();

    cout<<LCS(s1,s2,m,n)<<endl;
}