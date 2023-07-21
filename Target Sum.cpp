// same problem different terminology
#include <bits/stdc++.h> 
int countPartitions(int n, int d, vector<int> &arr) 
{
    int sum = 0;
    for(int i=0 ; i<arr.size(); i++) sum+=arr[i];
    if((sum+d)%2==1) return 0;
    int k = (sum+d)/2;
    vector<int> prev(k+1,0) , cur(k+1,0);
    
    if(arr[0]==0) prev[0] =2;
    else prev[0] = 1;
    if(arr[0]!=0 && arr[0]<=k) prev[arr[0]] = 1;

    for(int i=1 ; i<n ; i++)
    {
        for(int target= 0 ; target<=k ; target++)
        {
            int nottake = prev[target];
            int take = 0;
            if(target>=arr[i]) take = prev[target-arr[i]];
            cur[target] = (take +nottake);
        }
        prev = cur;
    }
    return prev[k];
}
int targetSum(int n, int target, vector<int>& arr) {
   return countPartitions(n,target,arr);
}
// same problem different terminology
