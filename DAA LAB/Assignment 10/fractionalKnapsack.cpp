#include<bits/stdc++.h>
using namespace :: std;

class Item{
    public:
        int weight, value;
};

bool comp(Item a, Item b){
    return (1.0*a.value)/a.weight > (1.0*b.value)/b.weight;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    double ans=0;
    sort(arr, arr+n, comp);
    int id=0;
    while(W && id<n){
        if(W>=arr[id].weight){
            W-=arr[id].weight;
            ans+=arr[id].value;
        }
        else{
            ans+=((1.0*arr[id].value)/(1.0*arr[id].weight))*W;
            W=0;
        }
        id++;
    }
    return ans;
}

int main(){
    int n = 0, W = 0;
    cout<<"Enter the number of items: ";
    cin>>n;
    cout<<"Enter the size of knapsack: ";
    cin>>W;
    Item *arr = new Item[n];
    for(int i=0; i<n; i++){
        cout<<"Enter the weight and value for item "<<i+1<<":";
        cin>>arr[i].weight>>arr[i].value;
    }

    cout<<"The maximum value that can be accomodated = "<<fractionalKnapsack(W, arr, n);
    return 0;
}