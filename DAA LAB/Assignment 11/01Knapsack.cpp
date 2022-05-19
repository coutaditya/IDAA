#include<bits/stdc++.h>
using namespace :: std;

int knapsack(int wt[], int val[], int n, int W){
	int t[102][1002];
	for(int i=0; i<n+1; i++){
		for(int j=0; j<W+1; j++){
			if(i==0 || j==0){
				t[i][j]=0;
			}
		}
	}
	
	for(int i=1; i<n+1; i++){
		for(int j=1; j<W+1; j++){
			if(wt[i-1]<=j){
				t[i][j]= max(val[i-1]+t[i-1][j-wt[i-1]], t[i-1][j]);
			}
			else{
				t[i][j]= t[i-1][j];
			}
		}
	}
	
	return t[n][W];
}

int main(){
	int n=0;
	cin>>n;
	int*wt=new int [n];
	int*val=new int [n];
	for(int i=0; i<n; i++){
		cin>>wt[i]>>val[i];
	}
	int W=0;
	cin>>W;
	cout<<"The maximum value that can be accomodated = "<<knapsack(wt, val, n, W);
	return 0;
}
