#include <bits/stdc++.h>
using namespace :: std;

void insertionSort(vector<int> &arr, int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        cout<<"key = "<<key<<"\n";
        j = i - 1;
 
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        for(auto i: arr){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return;
}
 

int main(){
    vector<int> arr = {7,8,2,5,6};
    int n = arr.size();

    insertionSort(arr, n);
    cout<<"Sorted Array: ";
    for(auto i:arr){
        cout<<i<<" ";
    }

    return 0;
}