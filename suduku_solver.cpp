#include<iostream>
#include<cmath>
using namespace std;
// helper function 
bool isSafe(int mat[][9],int i ,int j,int no){


  //check for row and column
  for(int k=0;k<9;k++){
    if(mat[i][k]==no || mat[k][j]==no){
      return false;
    }
  }
  //check for 3*3 box
 
  int sx = (i/3)*3;
  int sy = (j/3)*3;

  for(int x=sx;x<sx+3;x++){
    for(int y=sy;y<sy+3;y++){
      if(mat[x][y]==no){
        return false;
      }
    }
  }
  return true;
}




bool solveSudoku(int mat[][9],int i,int j,int n) {
  //base case
  if(i==n){
    //print the matrix
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
      }
       cout<<mat[i][j]<<" ";
    }
   
    return true;
  }
  
  
  // rec case
 if(j==n){
   return solveSudoku(mat,i+1,0,n);
 }

  //skip thr prefilled cell
  if(mat[i][j]!=0){
    return solveSudoku(mat,i,j+1,n);
  }

  // cell to be filled
  // try out all the possible values
  for(int no=1;no<=9;no++){
    // whether it is safe to place the no or not
    if(isSafe(mat,i,j,no)){
      
      mat[i][j]=no;
      bool solveSudoko = solveSudoku(mat,i,j+1,n);
      if(solveSudoko){
        return true;
      }
    }
    
  }
  // backtracking // if no option works 
  mat[i][j]=0;
  return false;
}


int main(){
  int n = 9;
  int mat[9][9] =
      { {1,0,6,5,0,8,4,0,0},
      {2,1,0,0,3,0,0,0,8},
      {0,8,7,0,0,0,0,3,1},
      {0,0,3,0,1,0,0,8,0},
      {2,1,3,4,5,0,0,0,6},
      {5,6,8,9,0,5,7,9,9},
      {2,1,0,0,3,0,0,0,8},
      {0,8,7,0,0,0,0,3,1},
      {0,0,3,0,1,0,0,8,0}};

  
     if(!solveSudoku(mat,0,0,n)){
       cout<<"No solution exists"<<endl;
     }

}