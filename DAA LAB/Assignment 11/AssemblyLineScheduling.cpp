#include<bits/stdc++.h>
using namespace :: std;

int t[2][10000];

int solveTab(int**A, int**P, int e[], int s[], int n){
	int t[2][n];
	
	for(int i=0; i<2; i++){
		t[i][0] = s[i]+A[i][0];
	}
	
	for(int j=1; j<n; j++){
		for(int i=0; i<2; i++){
			t[i][j] = A[i][j]+min(t[i][j-1], P[!i][j]+t[!i][j-1]);
		}
	}
	
	return min(e[0]+t[0][n-1], e[1]+t[1][n-1]);
}

int solve(int**A, int**P, int e[], bool path, int i, int n){
	if(i==n-1){
		return e[path]+A[path][i];
	}

	if(t[path][i]!=-1){
		return t[path][i];
	}

	return t[path][i] = A[path][i]+min(solve(A, P, e, path, i+1, n), solve(A, P, e, !path, i+1, n)+ P[path][i+1]);
}

int main(){
	memset(t, -1, sizeof(t));
	int n=0;
	cin>>n;
	int**A=new int*[2];
	int**P=new int*[2];
	for(int i=0; i<2; i++){
		A[i]=new int [n];
		P[i]=new int [n];
	}
	
	int start[2];
	for(int i=0; i<2; i++){
		cin>>start[i];
	}
	for(int i=0; i<2; i++){
		for(int j=0; j<n; j++){
			cin>>A[i][j];
		}
	}
	for(int i=0; i<2; i++){
		for(int j=0; j<n; j++){
			cin>>P[i][j];
		}
	}
	int end[2];
	for(int i=0; i<2; i++){
		cin>>end[i];
	}
	
	// cout<<min(start[0]+solve(A, P, end, false, 0, n), start[1]+solve(A, P, end, true, 0, n))<<"\n";
	cout<<"The time taken = "<<solveTab(A, P, end, start, n)<<"\n";
	return 0;
}
