// recur and memo
#include<bits/stdc++.h>
int f(int w, vector<int> &profit, vector<int> &weight,int index,vector<vector<int>>& dp)
{
    if(index==0)
    {
        return (w/weight[0])*profit[0];
    }
    if(dp[index][w]!=-1) return dp[index][w];

    int nottake = f(w,profit,weight,index-1,dp);
    int take = INT_MIN;
    if(w>=weight[index]) take = profit[index]+f(w-weight[index],profit,weight,index,dp);
    return dp[index][w]=max(take,nottake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n,vector<int> (w+1,-1));
    return f(w,profit,weight,n-1,dp);
}
// recur and memo

// tabulation
#include<bits/stdc++.h>
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n,vector<int> (w+1,0));

    for(int i=0; i<=w ; i++)
    {
        dp[0][i] = (i/weight[0])*profit[0];
    }

    for(int i=1; i<n ;i++)
    {
        for(int wt = 0 ; wt<=w ; wt++)
        {
            int nottake = dp[i-1][wt];
            int take = INT_MIN;
            if(weight[i]<=wt) take = profit[i] + dp[i][wt-weight[i]];
            dp[i][wt] = max(take , nottake);
        }
    }
    return dp[n-1][w];

}
// tabulation

// space opti
#include<bits/stdc++.h>
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<int> prev(w+1,0);

    for(int i=0; i<=w ; i++)
    {
        prev[i] = (i/weight[0])*profit[0];
    }

    for(int i=1; i<n ;i++)
    {
        for(int wt = 0 ; wt<=w ; wt++)
        {
            int nottake = prev[wt];
            int take = INT_MIN;
            if(weight[i]<=wt) take = profit[i] + prev[wt-weight[i]];
            prev[wt] = max(take , nottake);
        }
    }
    return prev[w];

}
// space opti
