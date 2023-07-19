// recur and memo
#include <bits/stdc++.h> 
int mod = 1e9+7;
int f(vector<int> &arr, int k, int index, vector<vector<int>>& dp)
{
    if(index==0)
    {
        if(k==0 && arr[0]==0) return 2;
        if(k==0 || k==arr[0]) return 1;
        return 0;
    }
    if(dp[index][k]!=-1) return dp[index][k];

    int notTake = f(arr,k,index-1,dp);
    int take = 0;
    if(arr[index]<=k) take = f(arr,k-arr[index], index-1,dp);
    return dp[index][k] = (take%mod +notTake%mod)%mod;
}
int countPartitions(int n, int d, vector<int> &arr) 
{
    int sum = 0;
    for(int i=0 ; i<arr.size(); i++) sum+=arr[i];
    if((sum+d)%2==1) return 0;
    int k = (sum+d)/2;
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return f(arr, k, n-1,dp);
}
// recur and memo

// tabulation
#include <bits/stdc++.h> 
int mod = 1e9+7;
int countPartitions(int n, int d, vector<int> &arr) 
{
    int sum = 0;
    for(int i=0 ; i<arr.size(); i++) sum+=arr[i];
    if((sum+d)%2==1) return 0;
    int k = (sum+d)/2;
    vector<vector<int>> dp(n,vector<int>(k+1,0));
    
    if(arr[0]==0) dp[0][0] =2;
    else dp[0][0] = 1;
    if(arr[0]!=0 && arr[0]<=k) dp[0][arr[0]] = 1;

    for(int i=1 ; i<n ; i++)
    {
        for(int target= 0 ; target<=k ; target++)
        {
            int nottake = dp[i-1][target];
            int take = 0;
            if(target>=arr[i]) take = dp[i-1][target-arr[i]];
            dp[i][target] = (take%mod +nottake%mod)%mod;
        }
    }
    return dp[n-1][k];

}
//tabulation

//space optimum
#include <bits/stdc++.h> 
int mod = 1e9+7;
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
            cur[target] = (take%mod +nottake%mod)%mod;
        }
        prev = cur;
    }
    return prev[k];

}
//space optimum
