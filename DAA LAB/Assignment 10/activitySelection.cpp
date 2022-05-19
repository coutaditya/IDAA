#include<bits/stdc++.h>

#define int long long int
#define ff first
#define ss second
#define pb push_back
#define pii pair<int, int>

using namespace :: std;

bool comp(pii a, pii b){
	return a.second<b.second;
}

int32_t main(){

    int n=0;
    cout<<"Enter the number of activities: ";
    cin>>n;
    vector<pii> v;

    for(int i=0; i<n; i++){
        pii p;
        cout<<"Enter the start time and end time of job"<<i+1<<":";
        cin>>p.first>>p.second;	
        v.push_back(p);
    }

    sort(v.begin(), v.end(), comp);

    int ans=0;
    int end=0;
    int i=0;
    while(i<n){
        if(v[i].first<end){
            i++;
        }
        else{
            end = v[i].second;
            i++;
            ans++;
        }
    }

    cout<<"The number of jobs that can be done are: "<<ans<<"\n";

	return 0;
}