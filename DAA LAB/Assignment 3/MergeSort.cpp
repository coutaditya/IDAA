#include<iostream>
using namespace :: std;

void merge(int A[], int l, int m, int r){
	int n1=m-l+1;
	int n2=r-m;
	
	int t1[n1];
	int t2[n2];
	cout<<"l = "<<l<<" m = "<<m<<" r = "<<r<<"\n";
	cout<<"Left Array: ";
	for(int i=0; i<n1; i++){
		t1[i]=A[l+i];
		cout<<t1[i]<<" ";
	}
	cout<<"\nRight Array: ";
	for(int i=0; i<n2; i++){
		t2[i]=A[m+i+1];
		cout<<t2[i]<<" ";
	}
	cout<<"\n";
	
	int i=0, j=0, k=l;
	while(i<n1 && j<n2){
		if(t1[i]<t2[j]){
			A[k]=t1[i];
			i++;
		}
		else{
			A[k]=t2[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		A[k]=t1[i];
		k++;
		i++;
	}
	while(j<n2){
		A[k]=t2[j];
		k++;
		j++;
	}
	cout<<"Merged Array: ";
	for(int x=0; x<k; x++){
		cout<<A[x]<<" ";
	}
	cout<<"\n\n";
}

void mergeSort(int A[], int l, int r){
	if(l>=r){
		return;
	}
	int m=(l+r)/2;
	mergeSort(A, l, m);
	mergeSort(A, m+1, r);
	merge(A, l, m, r);
}

void storeData(int A[], int n){
	for(int i=0; i<n; i++){
		cin>>A[i];
	}
}

void printArray(int A[], int n){
	for(int i=0; i<n; i++){
		cout<<A[i]<<" ";
	}
	cout<<"\n";
}

int main(){
	int n=0;
	cin>>n;
	int*A=new int [n];
	storeData(A, n);
	mergeSort(A, 0, n-1);
	cout<<"The sorted array is: ";
	printArray(A, n);
	return 0;
}
