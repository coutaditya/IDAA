#include<bits/stdc++.h>
using namespace :: std;

// we assume that each job takes 1 unit time to complete
class Job{
    public:
        int dead, profit;
};

bool comp(Job a, Job b){
    return a.profit>b.profit;
}

vector<int> JobScheduling(Job arr[], int n) 
{ 
    int md=0;
    for(int i=0; i<n; i++){
        md=max(md, arr[i].dead);
    }
    vector<int> avail(md+1, -1);
    sort(arr, arr+n, comp);
    
    int pro=0, count=0;
    for(int i=0; i<n; i++){
        int j=arr[i].dead;
        while(j>0 && avail[j]!=-1){
            j--;
        }
        if(j>0 && avail[j]==-1){
            avail[j]=i;
            pro+=arr[i].profit;
            count++;
        }
    }
    return {count, pro}; 
} 

int main(){
    int n = 0;
    cout<<"Enter the number of jobs: ";
    cin>>n;
    Job* arr = new Job[n];
    for(int i=0; i<n; i++){
        cout<<"Enter the deadline and profit for job"<<i+1<<":";
        cin>>arr[i].dead>>arr[i].profit;
    }
    vector<int> ans = JobScheduling(arr, n);

    cout<<"count of jobs = "<<ans[0]<<"\nprofit = "<<ans[1];
    return 0;
}