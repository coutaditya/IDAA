#include<bits/stdc++.h>
using namespace :: std;

// O(n^2)
void selection_sort(vector<int> &v){
    // Array from 0 to i-1 is sorted, i to n is unsorted
    int i=0;
    while(i<v.size()){
        int mn = INT_MAX;
        int id = -1;
        for(int j=i; j<v.size(); j++){
            if(mn>v[j]){
                mn = v[j];
                id = j;
            }
        }
        swap(v[i], v[id]);
        i++;
        for(auto ele:v){
            cout<<ele<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    int n=0;
    cin>>n;
    vector<int> v(n, 0);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    selection_sort(v);
    cout<<"Sorted array: ";
    for(auto i:v){
        cout<<i<<" ";
    }
    return 0;
}