                            //program for the suduko solver
#include<bits/stdc++.h>
using namespace std;        
                            //this below function will tell us that if we can put number in the suduko cell or not
bool canweplace(int a[][9],int i,int j,int n,int num){  
        
    for(int k=0;k<n;k++){                               //for checking in the rows and columns
        if(a[k][j]==num || a[i][k]==num){
            return false;
        }
    }

                                                        //check for the subgrid
    int rn = sqrt(n);
    int sx = (i/rn)*rn;
    int sy = (j/rn)*rn;

    for(int x = sx;x<sx+rn;x++){
        for(int y= sy;y<sy+rn;y++){
            if(a[x][y]==num){
                return false;
            }
        }
    }
    return true;
}

                            //this function will solvee suduko if it is possible and print the solution otherwise will return false
bool sudukosolver(int mat[][9],int i,int j,int n){
    if(i==n){
        cout<<"\n\nSUDUKO SOLVED"<<endl;           //condition when suduko is solved   or BASE CASE
        for(int k=0;k<n;k++){
            for(int l =0;l<n;l++){
                cout<<mat[k][l]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

    if(j==n){                                                      //when we have to move into next row
        return sudukosolver(mat,i+1,0,n);
    }

    if(mat[i][j]!=0){                                           //no change when we found pre-inserted numbers in suduko
        return sudukosolver(mat,i,j+1,n);
    }

                                                        //RECURSION case
    for(int v=1;v<=n;v++){
        if(canweplace(mat,i,j,n,v)){
            mat[i][j] = v;
            bool couldwesolvesuduko  = sudukosolver(mat,i,j+1,n);
            if(couldwesolvesuduko){
                return true;
            }
        }
    }
    
                                                   //BACKTRACKING 
    mat[i][j] = 0;
    return false;

}
int main(){                                             //MAIN STARTS
    int mat[9][9];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>mat[i][j];
        }
    }
    sudukosolver(mat,0,0,9);
}                                                       //MAIN ENDS
