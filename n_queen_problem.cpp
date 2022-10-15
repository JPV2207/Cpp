// This is one of the popular questions from Backtracking which is : N Queen Problem

#include<bits/stdc++.h>
using namespace std;
int board[11][11];  // we have created a global array
bool isPossible(int n, int row, int col)
{
    // Same Coulmn
    for(int i=row-1;i>=0;i--)
    {
        if(board[i][col]==1)
        {
            return false;
        }
    }
    // Upper Left Column
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j]==1)
        {
            return false;
        }
    }
    // Upper Right Column
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++)
    {
        if(board[i][j]==1)
        {
            return false;
        }
    }
    return true;
}
void nQueenHelper(int n, int row)
{
    if(row==n)
    {
        // this implies that we have reached a solution and now we just need to print the matrix and return it.
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<board[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    
    // if we do not go in "if" statement above, then that implies that we haven't reached our solution and we need to place the queen at all possible positions and move to the smaller problem now.
    for(int j=0;j<n;j++)
    {
        if(isPossible(n,row,j))  // if it is possible to put the element, then we will place 1 there which denotes that the queen has been placed there.
        {
            board[row][j]=1;
            nQueenHelper(n,row+1); 
            board[row][j]=0;  // Once the small problem has been finished, we will backtrack and will initiialise the position to 0 or empty which implies that now the position of the queen has been changed
        }
    }
    return;
}
void placeNQueens(int n)  // Here n denotes the number of queens and not the number of rows and columns
{
    memset(board,0,11*11*sizeof(int));  // with the help of memset functionality, we have initialised our board from 0 to size of the matrix that we require
    nQueenHelper(n,0);  // We need to place the elements row - wise. Therefore, in starting the row is 0.

}
int main(){
    int n;
    cin>>n;
    placeNQueens(n);
    return 0;
}