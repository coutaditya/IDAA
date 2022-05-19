#include<bits/stdc++.h>
using namespace :: std;

int t[1002][1002];

int MCMmemoized(int A[], int i, int j){
	if(t[i][j]!=-1){
		return t[i][j];
	}
	else{
		int temp=INT_MAX;
		for(int k=i; k<j; k++){
			t[i][k]=MCMmemoized(A, i, k);
			t[k+1][j]=MCMmemoized(A, k+1, j);
			int tempAns=t[i][k]+t[k+1][j]+(A[i-1]*A[k]*A[j]);
			if(tempAns<temp){
				temp=tempAns;
			}
		}
		return t[i][j]=temp;
    }
}

int main(){
	int n=0;
	cin>>n;

	for(int i=0; i<n+1; i++){
		for(int j=0; j<n+1; j++){
			t[i][j]=-1;
			if(i>=j){
				t[i][j]=0;
			}
		}
	}

	int*A=new int [n];
	for(int i=0; i<n; i++){
		cin>>A[i];
	}

	cout<<"Minimum number of calculations required = "<<MCMmemoized(A, 1, n-1);
	return 0;
}
