#include <bits\stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr, int len){
    int smallest_index, temp;

    for(int i = 0; i < len - 1; i++){
        smallest_index = i;
        for(int j = i + 1; j < len; j++){
            if(arr[j] < arr[smallest_index])
                smallest_index = j;
        }

        if(smallest_index != i){
            swap(arr[i], arr[smallest_index]);
        }

        for(auto i:arr){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    int len;
    cout << "Array Length: ";
    cin >> len;

    vector<int> arr(len, 0);
    cout << "Array elements: ";
    for(int i = 0; i < len; i++)
        cin >> arr[i];

    selectionSort(arr, len);
    cout << "Sorted array: ";

    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<"\n";
    cout << endl;
}
