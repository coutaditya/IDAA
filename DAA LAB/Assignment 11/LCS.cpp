#include<bits/stdc++.h>
using namespace :: std;

int t[102][1002];

int LCS(string x, string y, int n, int m){
	if(n==0 || m==0){
		return t[n][m]=0;
	}
	if(t[n][m]!=-1){
		return t[n][m];
	}
	else{
		if(x[n-1]==y[m-1]){
			return t[n][m]=(1+LCS(x, y, n-1, m-1));
		}
		else{
			return t[n][m]=max(LCS(x, y, n-1, m),LCS(x, y, n, m-1));
		}
	}
}

int main(){
	for(int i=0; i<102; i++){
		for(int j=0; j<1002; j++){
			t[i][j]=-1;
		}
	}
	string x, y;
	cin>>x>>y;
	int n=x.length();
	int m=y.length();
	cout<<"Length of LCS = "<<LCS(x, y, n, m)<<endl;
	return 0;
}
