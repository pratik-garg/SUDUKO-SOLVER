#include<bits/stdc++.h>
using namespace std;
bool canweplace(int a[][9],int i,int j,int n,int num){
    for(int k=0;k<n;k++){
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
bool sudukosolver(int mat[][9],int i,int j,int n){
    if(i==n){
        cout<<"\n\nSUDUKO SOLVED"<<endl;
        for(int k=0;k<n;k++){
            for(int l =0;l<n;l++){
                cout<<mat[k][l]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

    if(j==n){
        return sudukosolver(mat,i+1,0,n);
    }

    if(mat[i][j]!=0){
        return sudukosolver(mat,i,j+1,n);
    }

    //rec case
    for(int v=1;v<=n;v++){
        if(canweplace(mat,i,j,n,v)){
            mat[i][j] = v;
            bool couldwesolvesuduko  = sudukosolver(mat,i,j+1,n);
            if(couldwesolvesuduko){
                return true;
            }
        }
    }
    mat[i][j] = 0;
    return false;

}
int main(){
    int mat[9][9];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>mat[i][j];
        }
    }
    sudukosolver(mat,0,0,9);
}
