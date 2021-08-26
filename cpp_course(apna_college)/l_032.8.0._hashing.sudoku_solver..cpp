#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define mii map<int,int>
#define v_vc vector<vector<char>>
#define m_pii_mii map<pii,mii>
#define v_mii vector<mii>

void print_sudoku(v_vc sudoku){
cout<<endl;
  for(auto i:sudoku){
    for(auto j:i)
      cout<<j<<" ";
    cout<<endl;
  }
}

void sudoku_solver_rec(int r, int c, v_vc &a, m_pii_mii mp, v_mii row, v_mii col){
  if(r==9) return print_sudoku(a);
  if(c==9)
    return sudoku_solver_rec(r+1,0,a,mp,row,col);
  if(a[r][c]!='.')
    return sudoku_solver_rec(r,c+1,a,mp,row,col);
  for(int i=1; i<=9 ;i++){
    int rw=r/3, cl=c/3;
    if(
      !mp[{rw, cl}][i] && 
      !row[r][i] && 
      !col[c][i]
    ){
      a[r][c] = i+'0';
      mp[{rw, cl}][i]  = 1;
      row[r][i] = 1;
      col[c][i] = 1;
      sudoku_solver_rec(r,c+1,a,mp,row,col);
      a[r][c] = '.';
      mp[{rw, cl}][i]  = 0;
      row[r][i] = 0;
      col[c][i] = 0;
    }
  }

}

void sudoku_solver(vector<vector<char>>&a){
  map<pii,mii> mp; 
  vector<mii> row(9);
  vector<mii> col(9);
  for(int i=0; i<9; i++)
    for(int j=0; j<9; j++){
      if(a[i][j]!='.'){
        int n = a[i][j]-'0';
        mp[{i/3, j/3}][n] = 1;
        row[i][n] = 1;
        col[j][n] = 1;
      }
    }
  sudoku_solver_rec(0,0,a,mp,row,col);
}

int main(){
  vector<vector<char>> sudoku = {
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
  };
  print_sudoku(sudoku);
  sudoku_solver(sudoku);
  return 0;
}