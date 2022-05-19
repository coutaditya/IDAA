#include <bits/stdc++.h>
using namespace std;

int **setAllZero(int n){
    int **res = new int *[n];
    for (int i=0; i<n; i++){
        res[i]=new int[n];
        for (int j=0; j<n; j++){
            res[i][j]=0;
        }
    }
    return res;
}
int **matrixAddition(int **arr, int **arr1, int n){
    int **res=setAllZero(n);
    for(int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            res[i][j]=arr[i][j]+arr1[i][j];
        }
    }
    return res;
}
int **matrixSubtraction(int **arr, int **arr1, int n){
    int **res = setAllZero(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            res[i][j]=arr[i][j]-arr1[i][j];
        }
    }
    return res;
}
int **matrixMultiplication(int **arr, int **arr1, int n){
    int **res=setAllZero(n);
    if(n==1){
        res[0][0]=arr[0][0]*arr1[0][0];
        return res;
    }
    int **a11=setAllZero(n/2);
    int **a12=setAllZero(n/2);
    int **a21=setAllZero(n/2);
    int **a22=setAllZero(n/2);
    int **b11=setAllZero(n/2);
    int **b12=setAllZero(n/2);
    int **b21=setAllZero(n/2);
    int **b22=setAllZero(n/2);
    for (int i=0; i<n/2; i++){
        for (int j=0; j<n/2; j++){
            a11[i][j]=arr[i][j];
            a12[i][j]=arr[i][n/2+j];
            a21[i][j]=arr[i+n/2][j];
            a22[i][j]=arr[i+n/2][j+n/2];
            b11[i][j]=arr1[i][j];
            b12[i][j]=arr1[i][n/2+j];
            b21[i][j]=arr1[i+n/2][j];
            b22[i][j]=arr1[i+n/2][j+n/2];
        }
    }
    int **p=matrixMultiplication(matrixAddition(a11, a22, n/2), matrixAddition(b11, b22, n/2), n/2);
    int **q=matrixMultiplication(matrixAddition(a21, a22, n/2), b11, n/2);
    int **r=matrixMultiplication(a11, matrixSubtraction(b12, b22, n/2), n/2);
    int **s=matrixMultiplication(a22, matrixSubtraction(b21, b11, n/2), n/2);
    int **t=matrixMultiplication(matrixAddition(a11, a12, n/2), b22, n/2);
    int **u=matrixMultiplication(matrixSubtraction(a21, a11, n/2), matrixAddition(b11, b12, n/2), n/2);
    int **v=matrixMultiplication(matrixSubtraction(a12, a22, n/2), matrixAddition(b21, b22, n/2), n/2);
    int **c11=matrixAddition(p, matrixAddition(v, matrixSubtraction(s, t, n/2), n/2), n/2);
    int **c12=matrixAddition(r, t, n/2);
    int **c21=matrixAddition(q, s, n/2);
    int **c22=matrixAddition(p, matrixAddition(u, matrixSubtraction(r, q, n/2), n/2), n/2);
    for(int i=0; i<n/2; i++){
        for(int j=0; j<n/2; j++){
            res[i][j]=c11[i][j];
            res[i][j+n/2]=c12[i][j];
            res[i+n/2][j]=c21[i][j];
            res[i+n/2][j+n/2]=c22[i][j];
        }
    }
    return res;
}
int main(){
    int n;
    cout<<"Enter the dimension : ";
    cin>>n;

    int **arr=setAllZero(n);
    int **arr1=setAllZero(n);
    
    cout<<"Enter the elements for first matrix : "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Enter the elements for second matrix : "<<endl;
    for(int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>arr1[i][j];
        }
    }
    int **res;
    res=matrixMultiplication(arr, arr1, n);
    cout<<"The multiplication of 2 matrices is : "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<res[i][j]<<"\t";
        }
        cout<<endl;
    }
}