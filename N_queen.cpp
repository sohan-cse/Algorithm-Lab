#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>>&board,int x,int y,int n){
    for(int row=0;row<x;row++){
        if(board[row][y]==1)return false;
    }

    int row=x;
    int col=y;

    //left upper diagonal
    while (row>=0&col>=0)
    {
        if(board[row][col]==1)return false;
        row--;
        col--;
    }

     row=x;
     col=y;

    //right upper diagonal
    while (row>=0&col<n)
    {
        if(board[row][col]==1)return false;
        row--;
        col++;
    }

    return true;
    
}

bool N_Queen(vector<vector<int>>&board,int row,int n){
    if(row>=n)return true;

    for(int col=0;col<n;col++){
        if(isSafe(board,row,col,n)){
            board[row][col]=1;
            if(N_Queen(board,row+1,n))return true;
            board[row][col]=0;
        }
    }
    return false;
}

int main(){
    int n;
    cout<<"Enter number of queen : ";
    cin>>n;
    vector<vector<int>>board(n,vector<int>(n,0));
    if(N_Queen(board,0,n)){
        for(auto row:board){
            for(auto i: row)
                cout<<i<<" ";
            cout<<endl;
        }
        
    }
    return 0;
}