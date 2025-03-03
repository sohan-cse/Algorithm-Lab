
#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<string>>&board,int x,int y,int n){

    for(int row=0;row<x;row++){
        if(board[row][y]=="Q")return false;
    }

    int row=x,col=y;
    while (row>=0&&col>=0)
    {
        if(board[row][col]=="Q")return false;
        row--,
        col--;
    }

    row=x,col=y;
    while (row>=0&&col<n)
    {
        if(board[row][col]=="Q")return false;
        row--,
        col++;
    }
    return true;
}

void nQueen(vector<vector<string>>&board,int row,int n,vector<vector<vector<string>>>&result){
    if(row==n){
        result.push_back(board);
        return;
    }
    for(int col=0;col<n;col++){
        if(isSafe(board,row,col,n)){
            board[row][col]="Q";
            nQueen(board,row+1,n,result);
            board[row][col]=".";//backtrack
        }
    }
}

int main(){
    cout<<"Enter number of Queen :";
    int n;
    cin>>n;
    vector<vector<string>>board(n,vector<string>(n,"."));
    vector<vector<vector<string>>>result;
    nQueen(board,0,n,result);
    cout<<"Total solution is : "<<result.size()<<endl;
    for(int i=0;i<result.size();i++){
        for(auto row:result[i]){
            for(auto ele: row){
                cout<<ele<< "  ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
