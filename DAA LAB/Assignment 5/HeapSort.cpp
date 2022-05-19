#include<bits/stdc++.h>
using namespace :: std;

void heapSort(vector<int> &v){
    int n=v.size();
    
    // Create the heap
    for(int i=1; i<n; i++){
        int t=i;
        while((t/2)>0 && v[t/2]>v[t]){
            swap(v[t/2], v[t]);
            t/=2;
        }
    }

    // Remove root from the heap and store it at the end
    for(int i=n-1; i>1; i--){
        swap(v[i], v[1]);
        int t=1;
        while((2*t+1)<i){
            int l=2*t;
            int r=2*t+1;

            if(l<i && r<i){
                if(v[l]<v[r]){
                   if(v[2*t]<v[t]){
                        swap(v[2*t], v[t]);
                        t=2*t;
                        continue;
                    } 
                }
                else{
                    if(v[2*t+1]<v[t]){
                        swap(v[2*t+1], v[t]);
                        t=2*t+1;
                        continue;
                    }
                }
            }
            else{
                break;
            }
        }
        if((2*t+1)==i){
            if(v[2*t]<v[t]){
                swap(v[2*t], v[t]);
                t=2*t;
            }
        }
    }
}

int main(){
    int n=0;
    cin>>n;
    vector<int> v(n+1, 0);   // because 1 based indexing
    for(int i=1; i<n+1; i++){
        cin>>v[i];
    }
    heapSort(v);
    
    for(int i=1; i<n+1; i++){
        cout<<v[i]<<" ";
    }
    return 0;
}