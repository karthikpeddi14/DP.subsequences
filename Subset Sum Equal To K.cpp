// recursion and memoization
#include <bits/stdc++.h> 
bool recursion(int index, int target , vector<int>& arr,vector<vector<int>>& dp)
{
    if(target==0 )return true;
    if(index==0) return (target==arr[0]);
    if(dp[index][target]!=-1) return dp[index][target];
    bool nottake = recursion(index-1, target,arr,dp);
    bool take = false;
    if(arr[index]<=target) take = recursion(index-1,target-arr[index],arr,dp);

    return dp[index][target] = take || nottake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) 
{
    vector<vector<int>> dp(n+1, vector<int>(k+1,-1));
    return recursion(n-1, k, arr,dp);
}
// recursion and memoization

//tabulation
#include <bits/stdc++.h> 

bool subsetSumToK(int n, int k, vector<int> &arr) 
{
    vector<vector<int>> dp(n, vector<int>(k+1,0));
    if(arr[0] <= k) dp[0][arr[0]] = true;
    for(int i=0 ; i<n ; i++)
    {
        dp[i][0] = true;
    }

    for(int i=1 ; i<n ; i++)
    {
        for(int target=1 ; target<=k ; target++)
        {
            dp[i][target] = dp[i-1][target];
            if(target-arr[i]>=0) dp[i][target] += dp[i-1][target-arr[i]];
        }
    }
    return dp[n-1][k];
}
//tabulation


//space optimum
#include <bits/stdc++.h> 

bool subsetSumToK(int n, int k, vector<int> &arr) 
{
    vector<int> prev(k+1,0), cur(k+1,0);
    if(arr[0] <= k) prev[arr[0]] = true;
    prev[0] = cur[0] = true;

    for(int i=1 ; i<n ; i++)
    {
        for(int target=1 ; target<=k ; target++)
        {
            cur[target] = prev[target];
            if(cur[target]!=1 && target-arr[i]>=0) cur[target] += prev[target-arr[i]];
        }
        prev = cur;
    }
    return prev[k];
}
//space optimum
