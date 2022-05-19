#include <bits/stdc++.h>
using namespace std;

int N;

void printArray(int arr[], int size){
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int partition (int arr[], int low, int high){
	int pivot = arr[low]; 
    cout<<"Pivot: "<<pivot<<"\n";
	int i = (high + 1); 

	for (int j = high; j >= low; j--){
		if (arr[j] > pivot){
			i--; 
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[low]);

    printArray(arr, N);
	return (i + 1);
}

void quickSort(int arr[], int low, int high){
	if (low < high){
		
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int main()
{
	int arr[] = {7,8,2,5,6};
	int n = sizeof(arr) / sizeof(arr[0]);
    N=n;
	quickSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}