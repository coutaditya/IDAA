#include<bits/stdc++.h>
using namespace :: std;

// O(n)
bool seq_search(vector<int> v, int target){
    for(int i=0; i<v.size(); i++){
        if(target==v[i]){
            return true;
        }
    }
    return false;
}

// O(log(n))
bool binarySearch(vector<int> v, int target){
    int i=0, j=v.size()-1;
    while(j>=i){
        int mid = i + (j-i)/2;
        if(v[mid]==target){
            return true;
        }
        else if(v[mid]>target){
            j=mid-1;
        }
        else{
            i=mid+1;
        }
    }
    return false;
}

int main(){
    int n = 0;
    cin>>n;
    vector<int> v(n, 0);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int target = 0;
    cin>>target;
    // cout<<"SEQUENTIAL SEARCH:\n";
    // if(seq_search(v, target)){
    //     cout<<"Present\n";
    // }
    // else{
    //     cout<<"Not Present\n";
    // }
    cout<<"BINARY SEARCH:\n";
    if(binarySearch(v, target)){
        cout<<"Present\n";
    }
    else{
        cout<<"Not Present\n";
    }

    return 0;
}