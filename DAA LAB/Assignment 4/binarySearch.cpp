#include<bits/stdc++.h>
using namespace :: std;

int binarySearch(vector<int> v, int s, int e, int key){
    if(s>e){
        return -1;
    }

    int mid = s+(e-s)/2;
    if(v[mid]==key){
        return mid;
    }
    else if(v[mid]>key){
        return binarySearch(v, s, mid-1, key);
    }
    else{
        return binarySearch(v, mid+1, e, key);
    }
}

int main(){
    vector<int> v = {1,2,3,6,8,9};
    int n = v.size();

    cout<<"Enter key: ";
    int key=0;
    cin>>key;
    int idx = binarySearch(v, 0, n-1, key);
    if(idx!=-1){
        cout<<"Present at index "<<idx;
    }
    else{
        cout<<"Element is not present";
    }
    return 0;
}